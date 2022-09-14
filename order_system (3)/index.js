const express = require('express');
const cors = require('cors');
const mogran = require('morgan');
const { pool } = require("./db");
const multer = require('multer');
// node 내장 모듈
const path = require('path');
const PORT = 8081;

const upload = multer({
  storage: multer.diskStorage({
    // 파일 업로드 위치
    destination: (req, file, done) => {
      done(null, "public/")
    },
    // 파일을 어떻게 저장할것인지 
    filename: (req, file, done) => {
      console.log(file);

      // 확장자 추출
      const ext = path.extname(file.originalname);
      // 확장자를 제외한 이름 
      const fileNameExeptExt = path.basename(file.originalname, ext);

      // 원본 파일이름 + 날짜 + 확장자
      // Date.now() 상세 년월일시초
      const saveFileName = fileNameExeptExt + Date.now() + ext;
      done(null, saveFileName)  
    }
  })
})



const app = express();
// cors 셋팅 
app.use(cors());
// http log 
app.use(mogran('dev'));
// body 데이터 받아오기 
app.use(express.json());
// 전역 폴더 셋팅
// 라우터 경로
// app.use("라우터 경로")
// /public 경로에 오면 expres.static을 보여줘라~~~

app.use("/public", express.static("public"));

app.get("/api/menus", async (req, res) => {
  try {
    const data = await pool.query("SELECT * FROM menus");
    return res.json(data[0]);
  } catch (error) {
    console.log(error);

    return res.json({
      success: false,
      message: "전체 메뉴 목록 조회에 실패하였습니다."
    });
  }

});

app.get("/api/menus/:id", async (req, res) => {
  try {
    const data = await pool.query("SELECT * FROM menus WHERE id = ?", [req.params.id]);
    console.log(data[0]);
    // data[0] -> data[0][0] 배열안의 객체에 접근
    return res.json(data[0][0]);

  } catch (error) {
    console.log(error);
    return res.json({
      success: false,
      message: "메뉴 조회에 실패하였습니다."
    })    
  }
})

// post("라우터 주소", upload , (req, res) )
app.post("/api/menus", upload.single('file'),async (req, res) => {
  try {
    // multer에서 정상처리해서 데이터를 넘겨주는 경우 req.file에 담겨서
    // console.log(req.file.path);
    // console.log(req.body.description);
    // console.log(req.body.name);
    const { name, description } = req.body
    const { path } = req.file

    // insert into [테이블명] (컬럼명) values (?,?), [] 
    const result = await pool.query('insert into menus (name, description, image_src) values(?,?,?)', [name, description, path])
   
    return res.json({
      success: true,
      message:"메뉴 등록에 성공하였습니다."
    })
  } catch (error) {
    console.log(error);
    return res.json({
      success: false,
      message: "메뉴 등록에 실패하였습니다."
    })
  }
})

app.patch("/api/menus/:id", async (req,res) => {
  // console.log(req)  
  try {
    const { name, description } = req.body
    const { id } = req.params
      // update [테이블명] set 컬럼명 = ?, 컬럼명 = ? 조건문 where 어떤 조건 = ?
     // 총3개의 컬럼중 2개를 변경시킬겁니다 -> name, description -> 어떤 기준으로 ? id , [ 넣을값"들"  ]
    // 여러분들 스스로 쿼리를 짜는시간을
    const result = await pool.query("update menus set name = ?, description = ? where id = ?", [name, description, id])

    return res.json({
      success: true,
      message: "메뉴 수정에 성공하였습니다."
    })
    // return res.render("menu_update.html", {
    //   data: result[0]
    // })
  } catch (error) {
    return res.json({
      success: false,
      message: "메뉴 수정에 실패하였습니다."
    })   
  }
})


















app.listen(PORT, () => console.log(`${PORT} 기동중`));



