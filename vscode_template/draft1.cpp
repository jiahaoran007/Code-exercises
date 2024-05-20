#include <iostream>

    // int a, b;
    // scanf("%d, %d", &a, &b);

    // //int c = 0;
    // //c = a + b;
    // printf("%d", a + b);

////////////////////////////////////////////////////////////////

    // int n, id, score;
    // scanf("%d", &n);

    // int j = n;
    // int a[maxn] = {0};

    // int k = 1, max;

    // while (j--)
    // {
    //     scanf("%d %d", &id, &score);
    //     a[id] += score;
    // }

    // max = -1;

    // for (int i = 1; i < n + 1; i++)
    // {
    //     if (a[i] > max)
    //     {
    //         max = a[i];
    //         k = i;
    //     }
        
    // }

    // printf("%d, %d", k, max);

//////////////////////////////////////////////////

// #include <cstdio>
// #include <cmath>
// #include <vector>
// #include <iostream>

// using namespace std;

// int main()
// {
//     int num;
//     int a, b, c;
//     int a1, b1, c1;
//     vector<int> arr;

//     int m, n;
//     scanf("%d %d",&m, &n);

//     for(int i = m; i <= n; i++)
//     {
//         c = i % 10;
//         b = ((i - c) / 10) % 10;
//         a = (i - b * 10 - c) / 100; 
//         a1 = pow(a, 3);
//         b1 = pow(b, 3);
//         c1 = pow(c, 3);
//         if(c1 + b1 + a1 == i)
//         {
//             arr.push_back(i);
//         }
//     }

//     if(arr.empty()) printf("NO");
//     else{
//             for(int i = 0; i < arr.size(); i++)
//             {
//                 printf("%d", arr[i]);
//                 if(i != arr.size() - 1) printf(" ");
//             }
//     }


    
/////////////////////////////////////////////////////////////
// #include <cstdio>
// #include <cmath>

// //#define mod(a,b) ((a) % (b))


// long long int mod1(long long int a, int b)
// {
//     long long int c = a % b;
//     return c;
// }

// int main()
// {
//     int n;
//     scanf("%d", &n);

//     long long int m = pow(2, n);
//     if(n < 64) printf("%lld", mod1(m, 1007));
//     else if(n > 64)
//     {
//         int n1 = 64;
//         int n2 = n - n1;
//         long long int a1 = pow(2, n1);
//         long long int a2 = pow(2, n2);
//         int result1 = mod1(a1, 1007) * mod1(a2, 1007);
//         int result2 = mod1(result1, 1007);
//         printf("%d", result2);
//     }


//     system("pause");
// }

//////////////////////////////////////////////////////////

// #include <cstdio>

// int isLeap(int n)
// {
//     if( (n % 400 == 0) || ((n % 4 == 0)&&(n % 100 != 0)))
//         return 1;
//     else return 0;
// }

// int main()
// {
//     int record[13][2] = {{0, 0}, {31, 31}, {28, 29}, {31, 31}, {30, 30}, {31, 31}, {30, 30}, {31, 31}, {31, 31}, {30, 30}, {31, 31}, {30, 30}, {31, 31}};
//     int year, mouth, day;
//     scanf("%d-%d-%d", &year, &mouth, &day);
//     int n, i;
//     scanf("%d", &n);
//     while(n--)
//     {
//         int m = isLeap(year);
//         if(day > 0)
//         {
//             day--;
//         }
//         //else //if(day <= 0)
//         if(day == 0)
//         {
//             mouth--;
//             if(mouth < 0)
//             {
//                 year--;
//                 mouth = 12;
//             }
//             day = record[mouth][m];
//         }

//     }
//     printf("%04d-%02d-%02d", year, mouth, day);

// }

///////////////////////////////////////////////////////////////////////////

// #include <cstdio>

// int main()
// {
//     int d, m, y, a;
//     scanf("%d-%d-%d", &y, &m, &d);   
//     if((m==1)||(m==2))//暮艢聜膰聻聹膰聵?盲赂????聢膰聢聳盲艧聦膰聹聢膷偶聸膷?聦膰聧藰莽沤??
//     {
//         m+=12;
//         y--;
//     }
//     a=(d+1+2*m+3*(m+1)/5+y+y/4-y/100+y/400)%7;//膰聵聼膰聹聼膷沤膭莽沤聴

//     printf("%d", a);
// }

//////////////////////////////////////////////////////////////////////////
// #include <cstdio>
// #include <iostream>

// int main()
// {
    // int x;
    // long long int y = 0;
    // scanf("%d", &x);

    // long long int product = 1;
    // while(x != 0)
    // {
    //     y += (x % 2) * product;
    //     x = x / 2;
    //     product = product * 10;
    // }

    // printf("%lld", y);
//     long long int x, product = 1;
//     scanf("%lld", &x);
//     int y = 0;

//     while (x != 0)
//     {
//         y += (x % 10) * product;
//         x = x / 10;
//         product = product * 2; 
//     }

//     printf("%d", y);
//     system("pause");
// }

////////////////////////////////////////////////////////////
// 


// #include <cstdio>
// #include <cstring>

// const int max = 10;

// int  main()
// {
//     int p, y = 0, i = 0, product = 1;
//     char str[max] = {'0'};
    
//     scanf("%s %d", str, &p);

//     int len = strlen(str);
//     int a[len];
//     while (len--)
//     {
//         int num = (str[i] >= '0'&&str[i] <= '9') ? (str[i] - '0') : (str[i] - 'A' + 10);
//         i++;

//         a[len] = num;

//         //y += num * product;
//         //product *= p; 
//         //printf("%d ", num);
//     }
//     for(int i = 0; i < len; i++ )
//     {
//         printf("%d ", a[i]);
//     }
//     //printf("%d", y);
// }

/////////////////////////////////////////////////////////////

// #include <cstdio>
// #include <cstring>

// const int max = 60;

// int main()
// {
//     int n, min = max, len, flag;
//     scanf("%d", &n);

//     char str[n][max];

//     for(int i = 0; i < n; i++)
//     {
//         scanf("%s", str[i]);
//         len = strlen(str[i]);
//         if(len < min) min = len;
//     }
    
//     for(int i = 0; i < min; i++)
//     {
//         for(int j = 1; j < n ; j++)
//         {
//             flag = 1;
//             if(str[j][i] != str[0][i])
//             {
//                 flag = 0;
//                 break;
//             }


//         }
//         if(flag)
//             {
//                 printf("%c", str[0][i]);
//             }
//     }
    
//     system("pause");
// }

///////////////////////////////////////////////////////////////
// #include <cstdio>
// #include <cstring>

// const int max = 110;

// int main()
// {
//     int count = 1; 
//     char  str[max];
//     scanf("%s", str);

//     int len = strlen(str);
//     for(int i = 0; i < len ; i++)
//     {
//         if(str[i] == str[i + 1])
//         {
//             count++;
//         }
//         if(str[i] != str[i + 1])
//         {
//             printf("%c %d\n", str[i], count);
//             count = 1;
//         }
//     }
// }

/////////////////////////////////////////////////////////////

// #include <cstdio>
// #include <cstring>

// const int max = 30;

// int main()
// {
//     char str[max];

//     scanf("%s", str);
//     int flag = 1, len;
//     if(!( (str[0] >= 'A' && str[0] <= 'Z')||(str[0] >= 'a' && str[0] <= 'z')||(str[0] == '_') ))
//     {
//         flag = 0;
//     }
//     //else flag = 0;
//     len = strlen(str);
//     for(int i = 1; i < len; i++)
//     {
//         if((str[i] >= 'A' && str[i] <= 'Z')||(str[i] >= 'a' && str[0] <= 'z')||(str[i] == '_')||(str[i] >= '0' && str[i] <= '9'))
//         {
//             flag = 1;
//         }
//     else flag = 0;
//     }
//     if(flag == 1) printf("YES");
//     else printf("NO");

//     system("pause");
// }

/////////////////////////////////////////////////////////////////
// #include <cstdio>
// #include <algorithm>

// using namespace std;

// const int max = 60;

// int main()
// {
//     int n, temp = 0, j1;
//     scanf("%d", &n);
//     int a[60];
//     for(int i = 0; i < n; i++)
//     {
//         scanf("%d", &a[i]);
//     }

//     for(int i = 0; i < n; i++)
//     {
//         temp = a[i];
//         for(int j = i + 1; j > 0; j--)
//         {
//             //temp = a[j];
//             if(temp < a[j - 1]&&(j - 1 >= 0))
//             {
//                 a[j] = a[j - 1];
//             }
//             else{
//                 j1 = j;
//                 break;
//             }

//         }
//         a[j1] = temp;
//     }
//     for(int i = 0; i < n; i++)
//     {
//         printf("%d", a[i]);
//     }
//     system("pause");
// }

//////////////////////////////////////////////////////////////////////////////////////
// #include <cstdio>
// #include <cstring>
// const int maxc = 60;
// const int maxl = 110;

// int main()
// {
//     int n;
//     scanf("%d", &n);
//     char str[maxc][maxl];

//     for(int i = 0; i < n; i++)
//     {
//         scanf("%s", str[i]);
//     }

//     for(int i = 1; i < n; i++)
//     {
//         char temp[maxl];
//         strcpy(temp, str[i]);
//         int j = i;
//         while(j - 1 >= 0 && (strcmp(str[j - 1], temp) > 0))
//         {
//             strcpy(str[j], str[j - 1]);
//             //a[j] = a[j - 1];
//             j--;
//         }
//         strcpy(str[j], temp);
//         //a[j] = temp;
//         //a[j] = a[i];

//     }

//     for(int i = 0; i < n; i++)
//     {
//         printf("%s\n", str[i]);
//     }   
// }

///////////////////////////////////////////////////////////////////////////////////
// #include <cstdio>

// const int maxl = 1010;
// int hash[maxl] = {0};

// int main()
// {
//     int n, m, x;
//     scanf("%d", &n);
//     for(int i = 0; i < n; i++)
//     {
//         scanf("%d", &x);
//         hash[x]++;
//     }

//     for(int i = 0; i < m; i++)
//     {
//         scanf("%d", &x);
//         if(hash[x] > 0) printf("1 ");
//         else printf("0");
//     }

//     system("pause");
// }

////////////////////////////////////////////////////////////////////////////////
// #include <cstdio>

// int dog(int n)
// {
//     if(n == 0)
//     {
//         printf("我的小鲤鱼");
//         return 0;

//     }

//     printf("抱着");
//     dog(n - 1);
//     printf("的我");

// }

// int main()
// {
//     int n;
//     scanf("%d", &n);
//     printf("吓得我抱起了");
//     dog(n);
// }

/////////////////////////////////////////////////////////////////////////////////
// #include <cstdio>
// #include <algorithm>
// using namespace std;

// const int maxl = 110;
// int a[maxl];

// // int digui(int a[], int n)
// // {
// //     int max;
// //     if(n == 1)
// //     {
// //         return max > a[0] ? max : a[0];
// //     }

// //     else{
// //         if(digui(a[n - 2], n - 2) > a[n - 1]) max = digui(a[n - 2], n - 2);
// //         else max = a[n - 1];
// //     }
// // }


// int isMax(int n)
// {
//     if(n == 1)
//     {
//         return a[1];
//     }
//     else{
//         return max(isMax(n - 1), a[n]);
//     }
// }
// int main()
// {
//     int n;
//     int a[maxl];

//     scanf("%d", &n);
//     for(int i = 1; i <= n; i++)
//     {
//         scanf("%d", &a[i]);
//     }
//     // for(int i = 1; i <= n; i++)
//     // {
//     //     printf("%d ", a[i]);
//     // }

//     //int m = isMax(n);
//     printf("%d", isMax(n));
//     system("pause");
// }
//////////////////////////////////////////////////////////////////////
// #include <cstdio>
// #include <algorithm>

// using namespace std;

// const int maxl = 30;

// int n, a[maxl][maxl];

// int shuta(int i, int j)
// {
//     if(i == n)
//     {
//         return a[n][j];
//     }
//     else{
//         return max(shuta(i + i, j), shuta(i + 1, j + 1)) + a[i][j];
//     }
// }

// int  main()
// {
//     scanf("%d", &n);
//     for(int i = 1; i <= n; i++)
//     {
//         for(int j = 1; j <= i; j++)
//         {
//             scanf("%d", &a[i][j]); 
//         }
//         //scanf("%d", &a[i][j]);
//     }

//     for(int i = 1; i <= n; i++)
//     {
//         for(int j = 1; j <= i; j++)
//         printf("%d\n", a[i][j]);
//     }

//      printf("%d", shuta(1, 1));
     
// }
///////////////////////////////////////////////////////////////////////////////
#include <cstdio>

// void spiral(int n)
// {
//     if(n == 0)
//     {
//         return;
//     }
//     else{

//     }
// }
// const int maxl = 25;
// int a[maxl][maxl];

// void spiral(int n)
// {
//     int top = 0, bottom = n - 1, left = 0, right = n - 1;
//     int i = 1;
//     while(i <= n * n)
//     {
//         for(int l = left; l <= right; l++)
//         {
//             a[top][l] = i++;
//         }
//         top++;
//         for(int t = top; t <= bottom; t++)
//         {
//             a[t][right] = i++;
//         }
//         right--;
//         for(int r = right; r >= left; r--)
//         {
//             a[bottom][r] = i++;
//         }
//         bottom--;
//         for(int b = bottom; b >= top; b++)
//         {
//             a[b][left] = i++;
//         }
//         left++;
//     }

// }

// int main()
// {
//     int n;
//     scanf("%d", &n);
//     spiral(n);
//     for(int i = 0; i < n; i++)
//     {
//         for(int j = 0; j < n; j++)
//         {
//             printf("%d", a[i][j]);
//         }
//         printf("\n");
//     }

// }

//////////////////////////////////////////////////////////////////////
// #include <cstdio>
// #include <algorithm>

// using namespace std;
// const int maxl = 100;
// int flag[maxl];

// int mul(int n)
// {
//     int count = 1;
//     for(int i = 0; i < n / 3; i++)
//     {
//         count = count * flag[i];
//     }
//     return count;
// }

// int main()
// {
//     int n, m, mm, m1 = 0, m2;
//     //int flag[maxl];
//     scanf("%d", &n);
//     if(n == 2) printf("1");
//     else{
//         for(int i = 0; i < n / 3; i++)
//         {
//             flag[i] = 3;
//         }
//         // for(int i = 0; i < n / 3; i++)
//         // {
//         //     printf("%d ", flag[i]);
//         // }
//     m = n % 3;
//     {
//         if(m == 1)
//         {
//             flag[n / 3 - 1] = 4;
//             m1 = mul(n);
//             flag[n / 3 - 1] = 2;
//             flag[n / 3] = 2;
//             m2 = mul(n + 2);
//             mm = max(m1, m2);
//         }
//         else if(m == 2)
//         {
//             flag[n / 3] = 2;
//             mm = mul(n + 1);
//         }
//         else if(m == 0)
//         {
//             mm = mul(n);
//         }
//     }

//     printf("%d", m);
//     }

    
// }

////////////////////////////////////////////////////////////////////////////////
// #include <cstdio>

// const int maxl = 1000;
// int b[maxl] = {0};

// int main()
// {
//     int  a[10];
//     for(int i = 0; i < 10; i++)
//     {
//         scanf("%d", &a[i]);
//     }
//     // for(int i = 0; i < 10; i++)
//     // {
//     //     printf("%d ", a[i]);
//     // }
//     // printf("\n");

//     int count = 0;
//     for(int i = 0; i < 10; i++)
//     {
//         while(!a[i])
//         {
//             b[count] = i;
//             count++;
//             a[i]--;
//         }
//     }
//     for(int j = 0; j <=count; j++)
//     {
//         printf("%d ", b[j]);
//     }   
// }
//////////////////////////////////////////////////////////////////////////////
// #include <cstdio>
// #include <algorithm>

// using namespace std;

// const int maxl = 10010;

// struct Range1
// {
//     int left;
//     int right;
//     Range1(){};
//     Range1(int left_, int right_): left(left_), right(right_) {}
// }range[maxl];


// bool cmp(Range1 a, Range1 b)
// {
//     if(a.left != b.left) return a.left > b.left;
//     else return a.right < b.right;
// }

// int main()
// {
//     int n;
//     scanf("%d", &n);
//     //Range1 range[maxl];
//     for(int i = 0; i < n; i++)
//     {
//         scanf("%d %d", &range[i].left, &range[i].right);
//         // scanf("%d %d", &range[i]())
//     }
//     sort(range, range + n, cmp);
//     // for(int i = 0; i < n; i++)
//     // {
//     //     printf("%d %d\n", range[i].left, range[i].right);
//     // }
//     // printf("\n");
//     int count = 1;
//     int flag = range[0].left;
//     for(int i = 1; i < n; i++)
//     {
//         if(range[i].right <= flag)
//         {
//             count++;
//             flag = range[i].left;
//         }
//     }
//     printf("%d", count);
// }

/////////////////////////////////////////////////////////////////////////////////
// #include <cstdio>

// const int maxl = 100010;
// int a[maxl];

// int search(int x, int length)
// {
//     int left = 0;
//     int right = length - 1;
//     // int mid = left + (right - left) / 2;
//     while(left < right)
//     {
//         int mid = left + (right - left) / 2;
//         if(x >= a[mid])
//         {
//             left = mid;
//         }
//         else{
//             right = mid - 1;
//         }
//     }
//     return right;
// }

// int isSearch(int x, int length)
// {
//     int left = 0;
//     int right = length - 1;
//     int mid = left + (right - left) / 2;
//     if(x == a[mid])
//     {
//         return mid;
//     }
//     while(a[mid] != x)
//     {
//         if(x < a[mid])
//         {
//             right = mid - 1;
//             mid = left + (right - left) / 2;
//         }
//         else{
//             left = mid + 1;
//             mid = left + (right - left) / 2;
//         }
//         if(left > right)
//         {
//             mid = -1;
//             break;
//         }
//     }
//     return mid;   
// }

// int main()
// {
//     int n, x;
//     scanf("%d %d", &n, &x);
//     for(int i = 0; i < n; i++)
//     {
//         scanf("%d", &a[i]);
//     }
//     int result1 = isSearch(x, n);
//     if(result1 == -1)
//     {
//         printf("%d", result1);
//     }
//     else{
//         int result2 = search(x, n);
//         printf("%d", result2);
//     }
//     // printf("%d", result2);
// }

//////////////////////////////////////////////////////////////////
#include <cstdio>

const int maxl = 10010;
int n;
int a[maxl];

int search()
{
    int left = 0;
    int right = n - 1;
    while(left < right)
    {
        int mid = left + (right - left) / 2;
        if(a[mid] == a[0])
        {
            return mid;
        }
        else if(a[mid] < a[0])
        {
            right = mid;
        }
        else{
            left = mid + 1;
        }
    }
    return left;
}

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("%d", search());
}