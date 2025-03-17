// 11723: ���� (�ǹ�5/��Ʈ����ŷ)
#include <iostream>
using namespace std;
/**[���� 11723] ����
/* - vector�� map���� �� ������ ������ �Ǵ��� ��� �ð��ʰ� �߻�!
/*   => �� ������ ������ 20. 32��Ʈ ũ�� int�� �� bit�� ������ ������ ����
/* - value�� i��° bit�� 1�̸�: ���� ���տ� i ���� O
/* - value�� i��° bit�� 1�̸�: ���� ���տ� i ���� X
 */

// ��� ���Ҹ� �����ϴ� �������� �����ϴ� �Լ�
void all(int& s)
{
    s = (1 << 21) - 1; // 1�� 21�� �������� �̵� �� 1�� ���� 0���� �ٲ�
}

// �� 0���� ���� ���������� �����ϴ� �Լ�
void empty(int& s)
{
    s = 0; // �� 0���� �ٲ�
}

// s �� n�� �߰��ϴ� �Լ� (�̹� ������ ����)
void add(int& s, int n)
{
    s |= (1 << n); // �����ϱ� ���� ���� s �� �ٲ�
}

void remove(int& s, int n) // s���� n�� �����Ѵ�
{
    s &= ~(1 << n); // ������ 0���� ���� ~(1 << n) -> �̰� ������ 0�̵�
}

// s�� n�� ������ 1�� ������ 0�� ����ϴ� �Լ�
int check(int& s, int n)
{
    if (s & (1 << n)) // n�ڸ��� 1�̸� 1�� ��ȯ
    {
        return 1;
    }
    else // n�ڸ��� 0�̸� 0�� ��ȯ
    {
        return 0;
    }
}

void toggle(int& s, int n) // s�� n�� ������ n�� �����ϰ� ������ �߰��Ѵ�
{
    s ^= (1 << n); // �� �� �ϳ� 1�̸� 1�� �ٲ�
}

int main()
{
    ios_base::sync_with_stdio(false); // ���� ����
    cin.tie(NULL);
    cout.tie(NULL);

    int m, x, s = 0;
    string op; //�Է� ���� ��ɾ�
    cin >> m; // ������ ��
    while (m--)
    {
        cin >> op;

        // x �ǿ����ڰ� �Էµ��� �ʴ� ������: all, empty
        if (op == "all")
        {
            all(s);
        }
        else if (op == "empty")
        {
            empty(s);
        }

        // x �ǿ����ڰ� �ԷµǴ� ������: add, remove, check, toggle
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