#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int main()
{
    //cout << "Hello World!" << endl;
    int N;
    int Q;
    int X;
    int count = 0;
    string instruct;
    queue<int> hbag;
    stack<int> mbag;
    cin >> N;
    int temp;
    //queue for harry FIFO
    //stack for monk LIFO
    for(int i=0;i<N;i++){
        cin >> temp;
        hbag.push(temp);
    }
    cin >> Q >> X;
    for(int i=0;i<Q && count != X;i++){
        cin >> instruct;
        if(instruct == "Harry"){
            count += hbag.front();
            mbag.push(hbag.front());
            hbag.pop();
        }else{
            count -= mbag.top();
            mbag.pop();
        }
    }
    if(count == X)
        cout << mbag.size();
    else
        cout << -1;
    return 0;
}
