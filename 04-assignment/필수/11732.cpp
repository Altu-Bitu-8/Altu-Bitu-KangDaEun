// 11723: 집합 (실버5/비트마스킹)
#include <iostream>
using namespace std;
/**[백준 11723] 집합
/* - vector나 map으로 각 원소의 유무를 판단할 경우 시간초과 발생!
/*   => 총 원소의 개수는 20. 32비트 크기 int의 각 bit에 원소의 유무를 저장
/* - value의 i번째 bit가 1이면: 현재 집합에 i 존재 O
/* - value의 i번째 bit가 1이면: 현재 집합에 i 존재 X
 */

// 모든 원소를 포함하는 집합으로 설정하는 함수
void all(int& s)
{
    s = (1 << 21) - 1; // 1을 21번 왼쪽으로 이동 후 1을 빼서 0으로 바꿈
}

// 다 0으로 만들어서 공집합으로 설정하는 함수
void empty(int& s)
{
    s = 0; // 다 0으로 바꿈
}

// s 에 n을 추가하는 함수 (이미 있으면 무시)
void add(int& s, int n)
{
    s |= (1 << n); // 연산하기 전과 비교해 s 를 바꿈
}

void remove(int& s, int n) // s에서 n을 제거한다
{
    s &= ~(1 << n); // 무조건 0으로 만듬 ~(1 << n) -> 이게 무조건 0이됨
}

// s에 n이 있으면 1을 없으면 0을 출력하는 함수
int check(int& s, int n)
{
    if (s & (1 << n)) // n자리에 1이면 1을 반환
    {
        return 1;
    }
    else // n자리에 0이면 0을 반환
    {
        return 0;
    }
}

void toggle(int& s, int n) // s에 n이 있으면 n을 제거하고 없으면 추가한다
{
    s ^= (1 << n); // 둘 중 하나 1이면 1로 바꿈
}

int main()
{
    ios_base::sync_with_stdio(false); // 성능 개편
    cin.tie(NULL);
    cout.tie(NULL);

    int m, x, s = 0;
    string op; //입력 받을 명령어
    cin >> m; // 연산의 수
    while (m--)
    {
        cin >> op;

        // x 피연산자가 입력되지 않는 연산자: all, empty
        if (op == "all")
        {
            all(s);
        }
        else if (op == "empty")
        {
            empty(s);
        }

        // x 피연산자가 입력되는 연산자: add, remove, check, toggle
        else
        {
            cin >> x;
            if (op == "add")
            {
                add(s, x);
            }
            else if (op == "remove")
            {
                remove(s, x);
            }
            else if (op == "check")
            {
                cout << check(s, x) << "\n";
            }
            else if (op == "toggle")
            {
                toggle(s, x);
            }
        }
    }
    return 0;
}