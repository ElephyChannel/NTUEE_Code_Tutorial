/* 學子文把code放上去

#include<iostream>
#include<iomanip>
#include<cmath>

using namespace std;

double down, up, a3, a2, a1, a0,h;
double n;
double temp;

double cal(double x){
    double res = 0;
    res = a3 * pow(x,3) + a2 * pow(x,2) + a1 * x + a0;
    //cout << "temp now is " << temp <<endl;
    //cout << n << endl ;
    //cout << pow(x,3) << endl ;
    //cout << pow(x,2) << endl ;
    //cout << x << endl ;
    return res;
}

int main(){

    int i, j ,k;
    int num;
    cin >> down >> up >> a3 >> a2 >> a1 >> a0 >> h;


    n = ((up-down) / h);
    //cout << n << endl ;


    num = (int)n;
    temp = 0;

    for(i=0;i<num;i++){
        temp +=  ((cal(down + h * i) + cal(down + h * (i+1) )));
    }

    temp = (temp * h) / 2;

    cout << fixed << setprecision(0) << temp << endl ;

    temp = 0;
    for(i=0;i<num;i++){
        temp +=  ((cal(down + h * i)));
    }

    temp *= h;

    cout << fixed << setprecision(0) << temp << endl ;


    return 0;
}

*/

/*change date into weekday
#include<iostream>
#include<iomanip>
#include<cmath>

using namespace std;
int n;
int year, month, day;
char trash;

int cal(double x){
    int res = 0;

    return res;
}



int check(int ruen){
     if (year <= 0 || month <= 0 || day <= 0) return 0;
     if (month > 12) return 0;

     if(month == 1) {
        if(day>31) return 0;
     }
     else if(month == 2) {
        if(ruen ==1) {
            if (day >29) return 0;
        }
        else if(ruen == 0){
            if(day > 28) return 0;
        }
     }
     else if(month == 3) {
        if(day>31) return 0;
     }
     else if(month == 4) {
        if(day>30) return 0;
     }
     else if(month == 5) {
        if(day>31) return 0;
     }
     else if(month == 6) {
        if(day>30) return 0;
     }
     else if(month == 7) {
        if(day>31) return 0;
     }
     else if(month == 8) {
        if(day>31) return 0;
     }
     else if(month == 9) {
        if(day>30) return 0;
     }
     else if(month == 10) {
        if(day>31) return 0;
     }
     else if(month == 11) {
        if(day>30) return 0;
     }
     else if(month == 12) {
        if(day>31) return 0;
     }

    return 1;
}

int main(){

    int i, j, k;
    //不知道題目會到幾年，先試試看ㄅ
    int ruen_nien[3001];
    int diff = 0;
    int month_check[13];

    {  //set month_check
        month_check[1] = 31;
        month_check[3] = 31;
        month_check[4] = 30;
        month_check[5] = 31;
        month_check[6] = 30;
        month_check[7] = 31;
        month_check[8] = 31;
        month_check[9] = 30;
        month_check[10] = 31;
        month_check[11] = 30;
        month_check[12] = 31;
    }

    for(i=0;i<3001;i++){
        if(i%400 == 0) ruen_nien[i] = 1;
        else if (i%100 == 0) ruen_nien[i] = 0;
        else if (i%4 == 0)   ruen_nien[i] = 1;
        else ruen_nien[i] = 0;
    }

   cin >> n;
   for(k=0;k<n;k++){
       cin >> year >> trash >> month >> trash >> day;

       if(check(ruen_nien[year]) == 1){
           diff = 0;
           for(i=1;i<year;i++){
               if(ruen_nien[i] == 1) diff+= 366;
               else diff += 365;
           }
           for(i=1;i<month;i++){
                if(i==2){
                   if(ruen_nien[year] == 1) diff+=29;
                   else diff += 28;
                   }
                else diff+= month_check[i];
           }
           diff += day;
           if(diff % 7 == 0) cout << "Sun" << endl;
           else if(diff % 7 == 1) cout << "Mon" << endl;
           else if(diff % 7 == 2) cout << "Tue" << endl;
           else if(diff % 7 == 3) cout << "Wed" << endl;
           else if(diff % 7 == 4) cout << "Thr" << endl;
           else if(diff % 7 == 5) cout << "Fri" << endl;
           else if(diff % 7 == 6) cout << "Sat" << endl;
       }
       else cout << "-1" << endl;
   }


    return 0;
}
*/


/*
#include<iostream>
#include<iomanip>
#include<cmath>

using namespace std;

char  ** map, ** mapcheck;
int height, width;
int now_y, now_x;

void check(){

    int i, j, k;
    for(i=1;i<=height;i++){
       for(j=1;j<=width+2;j++){
         cout << map[i][j];
       }
       cout << endl;
    }
}

void check_res(){

    int i, j, k;
    for(i=1;i<=height;i++){
       for(j=1;j<=width+2;j++){
         cout << mapcheck[i][j];
       }
       cout << endl;
    }
}

int main(){


    int i, j, k;
    int flag = 0;
    int start_y;

    cin >> height >> width;

    //This could overflow, if height or width is high enough
    map = new char * [height+2];
    for(i = 1; i <= height; i++) map[i] = new char[width+2];

    mapcheck = new char * [height+2];
    for(i = 1; i <= height; i++) mapcheck[i] = new char[width+2];

    //the coordinate is all integer
    for(i=1;i<=height;i++){
       for(j=1;j<=width;j++){
         cin >> map[i][j];
       }
    }

    //check();

    for(i=1;i<=height;i++){
        map[i][width + 1] = 'w';
    }
    //check();

    for(i=1;i<=height;i++){
        if(map[i][1] == '_') {
            now_y = i;
            start_y = i;
            break;
          }
    }

    for(i=1;i<=height;i++){
       for(j=1;j<=width;j++){
         mapcheck[i][j] = '0';
       }
    }

    while(1){
        //check if the program end
        if(map[now_y][now_x + 1] == 'w'){
            mapcheck[now_y ][now_x ] = '1';
            //check_res();
            break;
        }

        //here is the program to walk straight
        else if(map[now_y - 1][now_x ] == '_'){
           map[now_y][now_x] = '*';
           mapcheck[now_y][now_x] = '1';
           now_y --;
        }


        else if(map[now_y][now_x + 1] == '_'){
           map[now_y][now_x] = '*';
           mapcheck[now_y][now_x] = '1';
           now_x ++;
        }

        else if(map[now_y + 1][now_x ] == '_'){
           map[now_y][now_x] = '*';
           mapcheck[now_y][now_x] = '1';
           now_y ++;
        }

        else if(map[now_y][now_x - 1] == '_'){
           map[now_y][now_x] = '*';
           mapcheck[now_y][now_x] = '1';
           now_x --;
        }

        //here is the program to walk back
        else if(map[now_y][now_x + 1] == '*'){
           map[now_y][now_x] = '#';
           mapcheck[now_y][now_x] = '0';
           now_x ++;
        }
        else if(map[now_y + 1][now_x] == '*'){
           map[now_y][now_x] = '#';
           mapcheck[now_y][now_x] = '0';
           now_y ++;
        }
        else if(map[now_y - 1][now_x] == '*'){
           map[now_y][now_x] = '#';
           mapcheck[now_y][now_x] = '0';
           now_y --;
        }
        else if(map[now_y][now_x - 1] == '*'){
           map[now_y][now_x] = '#';
           mapcheck[now_y][now_x] = '0';
           now_x --;
        }


    }

    //cout << now_y << now_x << endl;


    for(i=1;i<=height;i++){
        mapcheck[i][width + 1] = 'w';
    }

    now_x = 1;
    now_y = start_y;

    while(1){
        //check if the program end
        if(mapcheck[now_y][now_x + 1] == 'w'){
            break;
        }

        //here is the program to walk straight
        else if(mapcheck[now_y - 1][now_x ] == '1'){
           mapcheck[now_y][now_x] = '*';
           now_y --;
           cout << "U";
        }

        else if(mapcheck[now_y][now_x + 1] == '1'){
           mapcheck[now_y][now_x] = '*';
           now_x ++;
           cout << "R";
        }

        else if(mapcheck[now_y + 1][now_x ] == '1'){
           mapcheck[now_y][now_x] = '*';
           now_y ++;
           cout << "D";
        }

        else if(mapcheck[now_y][now_x - 1] == '1'){
           mapcheck[now_y][now_x] = '*';
           now_x --;
           cout << "L";
        }
    }
    //cout << endl;
    //check_res();
    cout << endl;

    return 0;

}

*/

/*
// this takes you 30 minute , write faster , bitch!
#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;

int main(){

    int i, j, k;
    int N, M;
    int **matrixF, **matrixS;
    int ** NN , ** NM;
    int temp = 0;

    cin >> N >> M;

    matrixF = new int *[N];
    for(i=0;i<N;i++){
        matrixF[i] = new int[N];
    }

    matrixS = new int *[N];
    for(i=0;i<N;i++){
        matrixS[i] = new int[M];
    }

    NN = new int *[N];
    for(i=0;i<N;i++){
        NN[i] = new int[N];
    }

    NM = new int *[N];
    for(i=0;i<N;i++){
        NM[i] = new int[M];
    }

    for(i = 0;i < N;i++){
        for(j = 0;j < N;j++){
            cin >> matrixF[i][j];
        }
    }

    for(i = 0;i < N;i++){
        for(j = 0;j < M;j++){
            cin >> matrixS[i][j];
        }
    }

    cout << "Counter-clockwise rotation of the first matrix:" << endl;

    for(i = 0;i < N;i++){
        for(j = 0;j < N;j++){
            NN[i][j] = matrixF[j][N-i-1];
        }
    }

    for(i = 0;i < N;i++){
        for(j = 0;j < N;j++){
            cout << setw(5) << NN[i][j];
        }
        cout << endl;
    }


    cout << "Clockwise rotation of the first matrix:" << endl;

    for(i = 0;i < N;i++){
        for(j = 0;j < N;j++){
            NN[i][j] = matrixF[N-j-1][i];
        }
    }

    for(i = 0;i < N;i++){
        for(j = 0;j < N;j++){
            cout << setw(5) << NN[i][j];
        }
        cout << endl;
    }

    cout << "Transpose of the first matrix:" << endl;

    for(i = 0;i < N;i++){
        for(j = 0;j < N;j++){
            NN[i][j] = matrixF[j][i];
        }
    }

    for(i = 0;i < N;i++){
        for(j = 0;j < N;j++){
            cout << setw(5) << NN[i][j];
        }
        cout << endl;
    }

    cout << "Multiplication of the first and second matrix:" << endl;

    for(i = 0;i < N;i++){
        for(j = 0;j < M;j++){
            for(k = 0;k < N;k++){
                temp += matrixF[i][k] * matrixS[k][j];
            }
            NM[i][j] = temp;
            temp = 0;
        }
    }

    for(i = 0;i < N;i++){
        for(j = 0;j < M;j++){
            cout << setw(5) << NM[i][j];
        }
        cout << endl;
    }

    for(i = 0;i < N;i++){
        delete [] matrixF[i];
    }

    delete [ ]
    return 0;
}

*/

/* 要試著不用遞迴寫一遍
#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;

int map[32][32];
int mapcheck[32][32];

void flag(int row, int col, int n);

int main(){

    int i, j, k;
    int flag_num = 1;

    for(i = 0;i < 32;i++){
        for(j = 0;j < 32; j++){
            cin >> map[i][j];
        }
    }


    for(i = 0;i < 32;i++){
        for(j = 0;j < 32; j++){
            mapcheck[i][j] = map[i][j];
        }
    }


    for(i = 0;i < 32;i++){
        for(j = 0;j < 32; j++){
            if(mapcheck[i][j] == 1 ){
                flag(i,j,flag_num);
                flag_num ++;
            }
        }
    }



    for(i = 0;i < 32;i++){
        for(j = 0;j < 32; j++){
            cout << map[i][j];
            if(j!=31) cout << " ";
        }
        if(i!=31) cout << endl;
    }



    return 0;
}
void flag(int row, int col, int n){

    if((row>=0)&&(col>=0)&&(col<32)&&(row<32)&&(mapcheck[row][col]==1)){
        map[row][col] = n;
        //cout << "row col is now processing" << row  << "and"<< col << endl;
        mapcheck[row][col] = 0;

        flag(row+1,col,n);
        flag(row-1,col,n);
        flag(row,col+1,n);
        flag(row,col-1,n);
        flag(row+1,col+1,n);
        flag(row+1,col-1,n);
        flag(row-1,col+1,n);
        flag(row-1,col-1,n);

    }
}

*/


/*
#include <iostream>
#include <iomanip>
#include<cstring>
using namespace std;
int main( )
{
    int N;
    int i, j, k;
    int operate, operand;
    int num_sentence;
    char ** map;

    int **rank;
    int * num;

    cin >> N;

    //could overflow since the int array
    num_sentence = N;
    rank = new int *[N];
    num = new int[N];


    for(i=0;i<N;i++){
       rank[i] = new int[2000];
    }
    for(i=0;i<N;i++){
        rank[i][0] = i;
    }

    for(i=0;i<N;i++){
        for(j=0;j<=1999;j++){
            rank[i][j] = 0;
        }
    }

    num = new int[N];
    for(i=0;i<N;i++){
        num[i] = 1;
    }


    map = new char *[N];
    for(i=0;i<N;i++){
       map[i] = new char[101];
    }
    for(i=0;i<N;i++){
        cin >> map[i];
    }


    int flag = 0;
    while(cin >> operate >> operand) {
        num_sentence --;
        for(i=0;i<num[operand];i++){
            rank[operate][num[operate]+i] = rank[operand][i];
            rank[operand][i] = 0;

        }
        num[operate] += num[operand];
        num[operand] = 0;

        flag ++;
        if(flag == 3) break;
    }

    for(i=0;i<N;i++){
        cout << "num of i is " << num[i] << endl;
    }

    for(i=0;i<N;i++){
        for(j=0;j<num[i];j++){
            cout << i << "row is " << rank[i][j] << endl;
        }
    }
    return 0;
}

*/

/*
//PREPEND BEGIN
#include <iostream>
using namespace std;

#define N_MAX 55
//PREPEND END

//TEMPLATE BEGIN

void reverse(char m1[], char r[])
{
    int i, j, k;
    int flag=0;
    for(i=0;i<N_MAX;i++){
        if(m1[i]!='\0') flag++;
        else break;
    }

    for(i=0;i<flag;i++){
        r[flag-1-i] = m1[i];
    }

    //m1為原始字元陣列，r為reverse後的字元陣列
    //將原始字元陣列reverse，以利運算時位數的對齊
}

void bigMoneyAdd(char m1[], char m2[], int sum[])
{
    //m1為第一個大數，m2為第二個大數，sum為各位數相加後的int陣列
    int i, j, k;
    int carry = 0;
    char a[N_MAX]="", b[N_MAX]="";

    int flag=0;
    reverse(m1, a);
    //cout << a << endl;
    //cout << m2 << endl;
    reverse(m2, b);

    for(i=0;i<N_MAX;i++){
        if(a[i]!='\0'){
            flag ++;
            if(b[i] == '\0') b[i] = '0';
        }
        else break;
    }

    //cout << b[0] << b[2] << endl;

    for(i=0;i<flag;i++){
        //cout << a[i] + b[i] - 96 << endl;
        sum[i] = (carry + a[i] + b[i] - 96) % 10;
        carry = (carry + a[i] + b[i] - 96) / 10;

    }
    if(carry>0) {
        sum[i]= carry;
        flag++;
    }
    //將顛倒後的a, b依照位數相加(考慮進位問題)

}

void bigMoneySub(char m1[], char m2[], int diff[])
{
    int i, j, k;
    int flag = 0;
    //m1為第一個大數，m2為第二個大數，diff為各位數相減後的int陣列

    char a[N_MAX]="", b[N_MAX]="";
    reverse(m1, a);
    reverse(m2, b);

    for(i=0;i<N_MAX;i++){
        if(a[i]!='\0'){
            flag ++;
            if(b[i] == '\0') b[i] = '0';
        }
        else break;
    }
    //
    for(i=0;i<flag;i++){
        if(a[i]>=b[i]) {
            diff[i] = a[i]-b[i];
            //cout << diff[i];
        }
        else {
            a[i+1] --;
            a[i] = a[i] + 10;
            diff[i] = a[i]-b[i];
            //cout << diff[i];
        }
    }
    //將顛倒後的a, b依照位數相減(考慮退位問題)

}

void bigMoneyPrint(int num[])
{
    int i, j ,k;
    int check = 0;
    int flag2 = 0;

    for(i=N_MAX-1;i>=0;i--){
        if(num[i]>0) {
            flag2 = i + 1;
            break;
        }
    }

    cout << "$";
    check = flag2;
    for(i=(flag2) - 1;i>=0;i--){
        if(check == flag2)check -- ;
        else{
            if(check % 3 ==0) cout<< ",";
            check --;
        }
        cout << num[i];

    }
    //將num陣列中的數字依照題目格式輸出
    cout << endl;
}

//TEMPLATE END

//APPEND BEGIN
int main(){

    char a[N_MAX] = "",b[N_MAX] = "";
    int sum[N_MAX] = {0}, diff[N_MAX] = {0};
    //int i,j,k;
    cin >> a >> b;

    bigMoneyAdd(a, b, sum);
    bigMoneySub(a, b, diff);
    bigMoneyPrint(sum);
    bigMoneyPrint(diff);

    return 0;
}
//APPEND END

*/

/*
//PREPEND BEGIN
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    char _binary[16];
    char _float[6];

    for (int i = 0; i < 16; ++i)
        cin >> _binary[i];

    for (int i = 0; i < 6; ++i)
        cin >> _float[i];
//PREPEND END

//TEMPLATE BEGIN
    // TODOs
    // binary format to float format.
    int i, j, k;
    int exp = -15;
    int temp_exp;
    double temp_mul;
    double ans = 0;


    exp += 16*( _binary[1]-'0') + 8*( _binary[2]-'0') + 4 * ( _binary[3]-'0') + 2*( _binary[4]-'0') + ( _binary[5]-'0');
    temp_exp = exp;

    //set
    temp_mul = 1;
    if(exp>0){
        for(i=1;i<=exp;i++){
            temp_mul*=2;
        }
    }
    else if(exp ==0){
        temp_mul = 1;
    }
    else {
            for(i=exp;i<0;i++){
                temp_mul /= 2;
            }
    }
    ans += temp_mul;


    //for 迴圈很常寫錯 要注意
    temp_exp --;
    for(i=0;i<10;i++){
        temp_mul = 1;
        if(_binary[6+i] == '1'){
            if(temp_exp>0){
                for(j=1;j<=temp_exp;j++){
                    temp_mul *= 2;
                }
            }
            else if (temp_exp == 0){
                temp_mul = 1;
            }
            else {
                for(j=temp_exp;j<0;j++){
                    temp_mul /= 2;
                }
            }
        }
        else{
            temp_mul = 0;
        }

        ans += temp_mul;
        temp_exp--;
    }

    if(_binary[0] == '1') ans = -ans;

    //print
    if(ans>65504) cout << "infinity" << endl;
    else if(ans < -65504) cout << "-infinity" << endl;
    else if(ans == (int)ans ) cout << ans << endl;
    else{
        temp_mul = ans;
        for(i=0;;){
            temp_mul /=10;
            if(temp_mul == 0) break;
            i++;
        }
        cout << setprecision(i+10) << ans <<endl;
    }

    //below is second part
    int dot ;
    int ans_float[16];
    int temp_float[21] = {0};
    int temp_int[20] = {};
    int integer = 0;
    double fraction = 0;
    double weight = 1;
    // 把兩者合在一起
    // code 打不出來就先去做其他事
    //盡量用紙筆紀錄 不要一味腦內運轉
    if(_float[0]=='-') {
        ans_float[0] = 1;
        for(i=1;i<6;i++){
            if (_float[i] == '.') break;
        }
        dot = i;
        for(i=dot-1;i>0;i--){
            integer += weight * (_float[i]-'0');
            weight*=10;
        }

        weight = 0.1;
        for(i=dot+1;i<6;i++){
            fraction += weight *(_float[i]-'0');
            weight /=10;
        }
        i = 0;

        while(integer!=0){
            if(integer%2==1){
                temp_int[i] = 1;
                integer --;
                integer /= 2;
            }
            else if(integer%2==0){
                    temp_int[i] = 0;
                integer /= 2;
            }
            i++;
        }

        temp_exp = i;

        int flag = 0;
        for(j=0;j<21;j++){
            if(fraction==0) temp_float[j] = 0;
            else{
                fraction *=2;
                if(fraction >=1){
                    flag = 1;
                    temp_float[j] = 1;
                    fraction --;
                }
                else{
                    temp_float[j] = 0;
                    if(flag == 0) temp_exp--;
                }
            }
        }

        temp_exp--;
        i=5;
        exp = temp_exp+15;

        while(i>0){
            if(exp%2==1){
                ans_float[i] = 1;
                exp --;
                exp /= 2;
            }
            else if(exp%2==0){
                ans_float[i] = 0;
                exp /= 2;
            }
            i--;
        }

        for(j=19;j>=0;j--){
            if(temp_int[j]!=0) break;
        }
        if(j==0&&temp_float[0]==0) j=-1;

        if(j==-1){
            for(i=0;i<21;i++){
                if(temp_float[i]!=0) {
                    break;
                }
            }
            k=i;
        }
        else k=0;


        if(j=-1){
            temp_float[k] = 0;
            for(i=6;i<16;i++){
                ans_float[i] = temp_float[k];
                k++;
            }
        }
        else{
           for(i=6;i<16;i++){
                if(j>=0){
                    ans_float[i] = temp_int[j];
                    j--;
                }
                else ans_float[i] = temp_float[k];
                k++;
            }
        }

        for(i=0;i<16;i++){
            cout << ans_float[i];
        }
        cout << endl;
    }
    else {
        ans_float[0] = 0;
        for(i=0;i<6;i++){
            if (_float[i] == '.') break;
        }
        dot = i;
        for(i=dot-1;i>=0;i--){
            integer += weight * (_float[i]-'0');
            weight*=10;
        }

        weight = 0.1;
        for(i=dot+1;i<6;i++){
            fraction += weight *(_float[i]-'0');
            weight /=10;
        }
        i = 0;

        while(integer!=0){
            if(integer%2==1){
                temp_int[i] = 1;
                integer --;
                integer /= 2;
            }
            else if(integer%2==0){
                    temp_int[i] = 0;
                integer /= 2;
            }
            i++;
        }

        temp_exp = i;

        int flag = 0;
        for(j=0;j<21;j++){
            if(fraction==0) temp_float[j] = 0;
            else{
                fraction *=2;
                if(fraction >=1){
                    flag = 1;
                    temp_float[j] = 1;
                    fraction --;
                }
                else{
                    temp_float[j] = 0;
                    if(flag == 0) temp_exp--;
                }
            }
        }

        temp_exp--;
        i=5;
        exp = temp_exp+15;

        while(i>0){
            if(exp%2==1){
                ans_float[i] = 1;
                exp --;
                exp /= 2;
            }
            else if(exp%2==0){
                ans_float[i] = 0;
                exp /= 2;
            }
            i--;
        }

        for(j=19;j>=0;j--){
            if(temp_int[j]!=0) break;
        }
        if(j==0&&temp_float[0]==0) j=-1;

        if(j==-1){
            for(i=0;i<21;i++){
                if(temp_float[i]!=0) {
                    break;
                }
            }
            k=i;
        }
        else k=0;


        if(j=-1){
            temp_float[k] = 0;
            for(i=6;i<16;i++){
                ans_float[i] = temp_float[k];
                k++;
            }
        }
        else{
           for(i=6;i<16;i++){
                if(j>=0){
                    ans_float[i] = temp_int[j];
                    j--;
                }
                else ans_float[i] = temp_float[k];
                k++;
            }
        }

        for(i=0;i<16;i++){
            cout << ans_float[i];
        }
        cout << endl;


    }

//TEMPLATE END

//APPEND BEGIN
    return 0;
}
//APPEND END
*/

/*
#include <iostream>
#include <iomanip>
using namespace std;
int main() {
    int n;
    char **word;

    cin >> n;
    word = new char *[n];
    for (int i = 0; i < n; i++) {
        word[i] = new char[100];
    }
    for (int i = 0; i < n; i++) {
        cin >> word[i];
    }
    char **temp;
    temp = new char *[n];

    int m = 0;
    for (int i = 0; i < n; i++) {
        m = 0;
        while (word[i][m] != '\0') m++;
        temp[i] = new char[m + 1];
        for (int j = 0; j < m + 1; j++) {
            temp[i][j] = word[i][j];
        }
        delete[] word[i];
        word[i] = temp[i];
    }
    int a, b;
    int an, bn;
    char *p;
    char *ptemp;
    while (cin >> a >> b) {
        n--;
        an = 0;
        bn = 0;
        m = 0;
        while (word[a][m] != '\0') m++;
        an = m;
        m = 0;
        while (word[b][m] != '\0') m++;
        bn = m;
        p = new char[an + bn + 1];
        for (int i = 0; i < an; i++) p[i] = word[a][i];
        for (int i = 0; i < bn + 1; i++) p[an + i] = word[b][i];
        ptemp = word[a];
        word[a] = p;
        p = ptemp;
        delete[] p;
        for (int i = b; i < n; i++) {
            word[i] = word[i + 1];
        }
    }
    for(int i = 0; i<n; i++){
        cout << word[i] << endl;
    }
    return 0;
}

*/

/*
// setfill example
if (op == 'f'){

       for(int i =0; i<N;i++){
           if(i == _index) ans = header;
           else header =  (size_t*)(*header);
       }
        // TODO 1. find

    }
    else if (op == 'i'){
      size_t *_insertee_ans ;
        _insertee_ans = new size_t();

        size_t * temp;

        for(int i = 0 ;i < N; i++){
            if(i == _index){
               //cout << "address of header is = " << header << endl;
               temp = header;
               // cout << temp << endl;
               header =  (size_t*)(*header);
               // cout << temp <<  endl << header << endl;
               *temp = (size_t)_insertee_ans;
               // cout << temp <<endl << _insertee_ans <<endl;
               *_insertee_ans = (size_t) header;
               break;
            }
            else header =  (size_t*)(*header);
        }
    }
*/

/*HW2 第一題
#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

char sen[7][7];
int a1,a2,a3,a4,b1,b2,b3,b4;

void decode();
void encode();


int main()
{
    int i,j,k;
    int n;
    char ope;
    cin >>a1>>b1>>a2>>b2>>a3>>b3>>a4>>b4;
    cin >>n;

    //單純用來數次數，不能用來跑其他迴圈

    for(i=0;i<n;i++){

        cin >> ope;
        for(j=1;j<=6;j++){
            for(k=1;k<=6;k++){
                cin >> sen[j][k];
            }
        }

        if(ope=='e') encode();
        else if(ope =='d')decode();

    }

    return 0;
}

void decode(){

    char temp;
    int i,j,k;
    // step 1
    for(i=1;i<=6;i++){
            temp = sen[i][a1];
            sen[i][a1] = sen[i][b1];
            sen[i][b1] = temp;
    }
    //step 2
    for(i=1;i<=6;i++){
            temp = sen[a2][i];
            sen[a2][i] = sen[b2][i];
            sen[b2][i] = temp;
    }
    //step3
    for(i=1;i<=6;i++){
            temp = sen[i][a3];
            sen[i][a3] = sen[i][b3];
            sen[i][b3] = temp;
    }
    //step 4
    for(i=1;i<=6;i++){
            temp = sen[a4][i];
            sen[a4][i] = sen[b4][i];
            sen[b4][i] = temp;
    }

    for(i=1;i<=6;i++){
        for(j=1;j<=6;j++){
            cout << sen[i][j];
        }
    }
    cout << endl;
}


void encode(){

    char temp;
    int i,j,k;
     //step 4
    for(i=1;i<=6;i++){
            temp = sen[a4][i];
            sen[a4][i] = sen[b4][i];
            sen[b4][i] = temp;
    }


    //step3
    for(i=1;i<=6;i++){
            temp = sen[i][a3];
            sen[i][a3] = sen[i][b3];
            sen[i][b3] = temp;
    }


    //step 2
    for(i=1;i<=6;i++){
            temp = sen[a2][i];
            sen[a2][i] = sen[b2][i];
            sen[b2][i] = temp;
    }

    // step 1
    for(i=1;i<=6;i++){
            temp = sen[i][a1];
            sen[i][a1] = sen[i][b1];
            sen[i][b1] = temp;
    }
    for(i=1;i<=6;i++){
        for(j=1;j<=6;j++){
            cout << sen[i][j];
        }
    }
    cout << endl;

}
*/
#include <iostream>
#include <cmath>
#include "graphics.h"
using namespace std;
class elipso
{
public:
int x, y, a, b, c;
void initialize(int x0, int y0, int a0, int b0) {
x=x0; y=y0; a=a0; b=b0; // set center & semi-axes
c=sqrt(fabs(a*a-b*b));
show();
}
void show() {
ellipse(x, y, 0, 360, a, b); // draw a complete ellipse
circle(x+c, y, 1); // mark the positive focus
circle(x-c, y, 1); // mark the negative focus
}
double area() { return 3.14159*a*b; }
};
















