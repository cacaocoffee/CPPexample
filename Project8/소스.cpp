#include <random>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;


string printlotto(int i, string str)
{
    int n = 0;
    int lottonum[45] = { 0 };
    if (i != 0)
    {
        for (int j = 0; j < i; j++)
        {
            printf("���ڸ� �Է��ϼ���: ");
            cin >> n;
            lottonum[n] = 1;
        }
    }

    //�õ尪�� ��� ���� ���� ����̽�����
    random_device rd;
    mt19937 gen(rd()); //���� ���� ���� �ʱ�ȭ
    uniform_int_distribution<int> dis(1, 45);

    while(i<7)
    {
        int random = dis(gen);
        if (lottonum[random] == 0)
        {
            lottonum[random] = 1;
            i++;
        }
    }
    cout << "�ζ� �ڵ� ��÷ ��� : ";
    for (int num = 0; num < 45; num++)
    {
        if (lottonum[num] == 1)
        {
            cout << num+1<<" ";
           
            str += to_string(num + 1);
            str += " ";
        }
    }
    str += "\n";
    cout << endl;
    return str;
}
int main() {
    //���� ��� �κ�

    ofstream writeFile;
    writeFile.open("�ζǹ�ȣ��÷.txt");

    int mode = 0;


    
    string str = "�ζ� �ڵ� ��÷ ��� : ";

    int RepeatNum=0;//�ݺ�Ƚ��
    cout << "��÷�� Ƚ���� �Է����ּ��� : ";
    cin >> RepeatNum;

    for (int i = 0; i < RepeatNum; i++)
    {
        str = printlotto(0,str);
        writeFile.write(str.c_str(), str.size());
        str = "�ζ� �ڵ� ��÷ ��� : ";
    }

    return 0;
}