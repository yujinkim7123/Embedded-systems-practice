#include<iostream>

#include< vector >
#include< deque >
#include< algorithm >
#include< math.h >
#include< queue >
using  namespace std;


queue< int> tree[1030][2];
int base;
int end_base;
int result = 0;

void next_tree(int day, int now)
{
    //cout << now << " ";
    if (now == 1)
    {
        if (day % 2 == 0) {
            if (tree[now][1].empty()) return;
            result += tree[now][1].front();
            tree[now][1].pop();
        }
        else {
            if (tree[now][0].empty()) return;
            result += tree[now][0].front();
            tree[now][0].pop();
        }
    }
    else  if (now >= base)
    {
        if (tree[now][0].empty()) return;

        if (now % 2 == 0)
            tree[now / 2][1].push(tree[now][0].front());
        else
            tree[now / 2][0].push(tree[now][0].front());

        tree[now][0].pop();
    }
    else
    {
        if (day % 2 == 0)
        {
            if (tree[now][1].empty())  return;
            if (now % 2 == 0)
                tree[now / 2][1].push(tree[now][1].front());
            else
                tree[now / 2][0].push(tree[now][1].front());

            tree[now][1].pop();
        }
        else
        {
            if (tree[now][0].empty()) return;

            if (now % 2 == 0) 
                tree[now/2][1].push(tree[now][0].front());
            else
                tree[now/2][0].push(tree[now][0].front());

            tree[now][0].pop();
        }
    }

}

void push_tree(int day) {

    int sub_base = 1;

    while (sub_base <= end_base - 1)
    {
        next_tree(day, sub_base);
        sub_base++;
    }
}

int main(int argc, char** argv)
{
    //1에서 부터 시작한다.

    int h, k, r;
    cin >> h >> k >> r;

    base = pow(2, h);
    end_base = pow(2, h + 1);

    int sub_base = base;

    for (int j = sub_base; j < end_base; j++) {
        for (int i = 0; i < k; i++)
        {
            int a;
            cin >> a;
            //cout << a << " " << j <<" ";
            tree[j][0].push(a);
        }
    }

    int day = 1;
    while (r >= day)
    {
         sub_base = 1;

        while (sub_base <= end_base - 1)
        {
            next_tree(day, sub_base);
            sub_base++;
        }
        day++;
    }

    cout << result << " ";
    return  0;
}