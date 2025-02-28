#include <iostream>
#include <queue>
using namespace std;

queue<int> q;

int calQueue(queue<int>* q) {
    int len = q->size();

    if (len == 1) return 1;

    for (int i = 0; i < len; i++) {
        q->pop();
        if (q->size() <= 1) return q->front();

        q->push(q->front());
        q->pop();
    }
}

int main() {

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        q.push(i);
    }

    cout << calQueue(&q);
}

