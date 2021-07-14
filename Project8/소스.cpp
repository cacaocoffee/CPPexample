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
            printf("숫자를 입력하세요: ");
            cin >> n;
            lottonum[n] = 1;
        }
    }

    //시드값을 얻기 위한 랜덤 디바이스생성
    random_device rd;
    mt19937 gen(rd()); //난수 생성 엔진 초기화
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
    cout << "로또 자동 추첨 결과 : ";
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
    //파일 출력 부분

    ofstream writeFile;
    writeFile.open("로또번호추첨.txt");

    int mode = 0;


    
    string str = "로또 자동 추첨 결과 : ";

    int RepeatNum=0;//반복횟수
    cout << "추첨할 횟수를 입력해주세요 : ";
    cin >> RepeatNum;

    for (int i = 0; i < RepeatNum; i++)
    {
        str = printlotto(0,str);
        writeFile.write(str.c_str(), str.size());
        str = "로또 자동 추첨 결과 : ";
    }

    return 0;
}