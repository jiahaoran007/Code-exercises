#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <cmath>
#include <algorithm>
#include <windows.h>
#include <random>
#include <ctime>
#include <iomanip>
#define POS_X1 35       //1、菜单页，第一列所有功能输出起始位置的x坐标值；2、排序之后输出提示起点的X坐标值
#define POS_X2 40       //输入模块的提示语句起点的X坐标值
#define POS_X3 50       //第一次，调用输入模块或磁盘数据读入模块功能以外的其他功能，提示“系统中尚无学生成绩信息，请先输入”的起始位置的X坐标值
#define POS_X4 65       //菜单页，第二列所有功能输出起始位置的x坐标值；
#define POS_Y 3  
using namespace std;

const int K = 8; // 设置k值为5

//读入训练数据与测试数据
void read_data(const string& file_name, vector<vector<double>>& data, vector<float>& labels, int num_rows, int num_cols)
{
    ifstream data_file(file_name);
    if (data_file)
    {
        for (int row = 0; row < num_rows; ++row)
        {
            for (int col = 0; col < num_cols; ++col)
            {
                data_file >> data[row][col];
            }
            data_file >> labels[row];
        }
        //cout << "数据读入成功 " << file_name << endl;
    }
    else
    {
        //cerr << "无法打开文件 " << file_name << endl;
        exit(1);
    }
}

//随机生成rows × cols 大小的数组，模拟测试数据
void random_creation(vector<vector<float>> &random, int rows, int cols)
{
    // random_device rd;  // 非确定性随机数生成器，用于引擎的种子 
    // mt19937 gen(rd()); // 梅森旋转算法 32-bit 终极随机数生成器
    // uniform_real_distribution<float> dis(15.0, 20.0);  // 均匀分布在[15.0, 20.0)范围内的单精度随机数生成器

	default_random_engine e(time(0));
	uniform_real_distribution<double> u(5.0,30.0);

    //vector<vector<float>> random(rows, vector<float>(cols));

    for(int i=0; i<rows; ++i) {
        for (int j=0; j<cols; ++j) {
            float num = u(e);
            random[i][j] = num;
            //cout << setprecision(15) << num << " "; 
        }
        //cout << endl;
    }

    ofstream data_file("E:\\compile_test\\data1.txt");
    if(data_file.good()) {
        for(int i=0; i<rows; ++i) {
            for(int j=0; j<cols; ++j) {
                data_file << setprecision(15) << random[i][j] << " ";
            }
            data_file << " " << "2.0";
            data_file << endl;
        }
        cout << "数据已写入data1.txt" << endl;
    }
    else {
        cerr << "无法打开data1.txt" << endl;
    }
}

//knn算法进行分类
void knn(vector<float>& predict, vector<vector<double>>& train_data, vector<float>& train_labels, int train_num_rows, int train_num_cols, int test_num_rows, int test_num_cols, vector<vector<double>>& test_data, vector<float>& test_labels)
{
        // 对测试数据进行分类
    //float* predict = new float(test_num_rows);
    int correct_count = 0;
    int m = 0;
    int label_one = 0, label_two = 0, label_three = 0;
    float predicted_label;
    //int  count = 0;
    for (int i = 0; i < test_num_rows; ++i)
    {
        vector<pair<double, float>> distances(train_num_rows);
        for (int j = 0; j < train_num_rows; ++j)
        {
            double distance = 0;
            for (int k = 0; k < train_num_cols; ++k)
            {
                distance += pow(train_data[j][k] - test_data[i][k], 2);
            }
            distances[j] = {sqrt(distance), train_labels[j]};
        }
        sort(distances.begin(), distances.end()); // 按距离从小到大排序
        // 找出前K个最近邻的标签，并进行投票
        vector<int> votes(K, 0);
        for (int j = 0; j < K; j++)
        {
            //votes[distances[j].second]++;
            votes[j] = distances[j].second;
            //cout << votes[j] << " ";
        }
        //cout << endl;
        label_one = count(votes.begin(),votes.end(),0.0);
        label_two = count(votes.begin(),votes.end(),1.0);
        label_three = count(votes.begin(),votes.end(),2.0);
        cout << "label_one = " << label_one << " " << "label_two = " << label_two << " " << "label_three = " << label_three << "    ";
        int max = label_one;
        if(max < label_two)
        {
            max = label_two;
        }
        if(max < label_three)
        {
            max = label_three;
        }
           /*
        sort(votes.begin(), votes.end());
        for(int j = 1; j < K; ++j)
        {
            if(votes[j] != votes[j-1]){
                label_one = j;
                break;
            }
        }
        for(int j = label_one + 1; j < K; ++j)
        {
            if(votes[j] != votes[j-1]){
                label_two = j;
            break;
            }
        }       
        label_three = K - label_two; 
        label_two = label_two - label_one;
        cout << "label_one = " << label_one << " " << "label_two = " << label_two << " " << "label_three = " << label_three << endl;
        int max = label_one;
        if(max < label_two)
        {
            max = label_two;
        }
        if(max < label_three)
        {
            max = label_three;
        }
        */
        if(max == label_one)
        {
            predicted_label = 0.0;
        }
        if(max == label_two)
        {
            predicted_label = 1.0;
        }
        if(max == label_three)
        {
            predicted_label = 2.0;
        }
        
        if((max == label_one) && (max == label_two))
        {
            for(int j = 0; j < K; ++j)
            {
                if(distances[j].second == 0.0)
                {
                    predicted_label = 0.0;
                    break;
                }
                if(distances[j].second == 1.0)
                {
                    predicted_label = 1.0;
                    break;
                }
            }
        }
        if((max == label_one) && (max == label_three))
        {
            for(int j = 0; j < K; ++j)
            {
                if(distances[j].second == 0.0)
                {
                    predicted_label = 0.0;
                    break;
                }
                if(distances[j].second == 2.0)
                {
                    predicted_label = 2.0;
                    break;
                }
            }
        }
        if((max == label_three) && (max == label_two))
        {
            for(int j = 0; j < K; ++j)
            {
                if(distances[j].second == 2.0)
                {
                    predicted_label = 2.0;
                    break;
                }
                if(distances[j].second == 1.0)
                {
                    predicted_label = 1.0;
                    break;
                }
            }
        }
        
        //int predicted_label = max_element(votes.begin(), votes.end()) - votes.begin();
        //int  count = 0;
        //count++;
        predict[m] = predicted_label;
        m++;
        cout << predicted_label << endl;
        //cout << count << " ";

        if (predicted_label == test_labels[i])
        {
            correct_count++;
        }
    }

    double accuracy = (double)correct_count / test_num_rows;
    cout << endl;
    cout << "测试数据中符合预测的共计：" << correct_count << "条" << endl;
    cout << "准确率: " << accuracy << endl;
}
// asd
void SetPosition(int x, int y)
{
    HANDLE hOut;
    COORD pos;

    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(hOut, pos);
}
int Menu(void)
{
    int posy = 5;
    int option;                         //保存用户输入的操作代号的变量
    int i,j;
    SetPosition(POS_X3,posy);
    printf("今天你emo了吗（knn算法）\n");      //输出系统名
    //输出系统名和功能说明之间的两行短横线
    for(i=0; i<2; i++)
    {
        SetPosition(POS_X1, ++posy);
        for(j=0; j<55; j++)
        {
            printf("-");
        }
    }
    //输出系统支持的功能和对应的功能代号
    SetPosition(POS_X1,++posy);
    printf("1.原始数据预测");
    SetPosition(POS_X4,posy);
    printf("2.随机数据预测");
    SetPosition(POS_X1,posy+=2);
    printf("3.单独预测");
    
    printf("0.退出");
    //输出系统支持的功能与输入提示语之间的两行短横线
    for(i=0; i<2; i++)
    {
        SetPosition(POS_X1,++posy);
        for(j=0; j<55; j++)
        {
            printf("-");
        }
    }
    //提示用户输入所要执行的功能代号
    SetPosition(POS_X1,++posy);
    printf("请选择你想要进行的操作[0~2]: [  ]\b\b\b");
    scanf("%d",&option);
    return option;
}
void function3(vector<float>& predict,vector<float>& predict_random,vector<float>& test_labels,vector<float>& random_labels)
{
	int n=1;
	int m=1,m1=1;
	cout<<"                           1.原始数据预测值"<<endl;
	cout<<"                           2.随机数据预测值"<<endl;
	cout<<"                           0.退出"<<endl;
	 
	while(n!=0)
	{
		cout<<"输入想查询的数据类型 ";
		cin>>n;
		switch(n)
		{
			case 1:
				{
					while(m!=0)
					{
						cout<<"输入你想要查询的数据的序号";
						cin>>m;
						if(m!=0)
						{
							cout<<"预测值是"<<predict[m]<<" 正确值是"<<test_labels[m]<<endl;
						}
																										
					}
					cout<<"退出查询"<<endl; 
					break;
				}
			case 2:{
				      while(m1!=0)
				      {
				      	cout<<"输入你想要查询的数据的序号";
						cin>>m1;
						if(m1!=0)
						{
							cout<<"预测值是"<< predict_random[m1]<<" 正确值是"<<random_labels[m1]<<endl;
						}
						 
					  }
				       cout<<"退出查询"<<endl; 
				break;
			}
			case 0:
				{
					break; 
				}
			default:
			{
				cout<<"错误输入"<<endl;
				break; 
				}	
		}
		
	}
	
	 

				
}
int main()
{

    const int TRAIN_ROWS = 350;
    const int TRAIN_COLS = 62;
    vector<vector<double>> train_data(TRAIN_ROWS, vector<double>(TRAIN_COLS));
    vector<float> train_labels(TRAIN_ROWS);    
    read_data("E:\\compile_test\\train_emtion.txt", train_data, train_labels, TRAIN_ROWS, TRAIN_COLS);//读入训练数据

    // for (int j = 0; j < TRAIN_COLS; ++j)
    // {
    //     cout << train_data[0][j];
    // }
    //cout <<train_labels[1] << endl;

    const int TEST_ROWS = 150;
    const int TEST_COLS = 62;
    vector<vector<double>> test_data(TEST_ROWS, vector<double>(TEST_COLS));
    vector<float> test_labels(TEST_ROWS);
    read_data("E:\\compile_test\\test_emtion.txt", test_data, test_labels, TEST_ROWS, TEST_COLS);//读入测试数据

    //float predict[TEST_ROWS];

    vector<float> predict(TRAIN_ROWS);//记录每条测试数据的预测值（共150条）！！！
    const int ROWS = 100;
    const int COLS = 62;
	vector<vector<float>> random(ROWS, vector<float>(COLS));
	vector<vector<double>> random_data(ROWS, vector<double>(COLS));
	vector<float> predict_random(TRAIN_ROWS);////记录每条随机生成数据的预测值（共100条）！！！
	vector<float> random_labels(ROWS);  
    char ch;
    int num = 1;
    
    //system("pause");
    system("mode con cols=130 lines=60");
    system("color 0E");
    //system("pause");
    while(1)
    {
        system("cls");
        ch = Menu();
        //system("pause");
        switch(ch)
        {
        	case 0:
                system("cls");
                SetPosition(0,10);
                printf("退出系统！\n");
                exit(0);
        	case 1:
        		system("cls");
        		 knn(predict, train_data, train_labels, TRAIN_ROWS, TRAIN_COLS, TEST_ROWS, TEST_COLS, test_data, test_labels);//功能1：对测试数据进行预测
                 cout << endl;
                 system("pause");
                 break;
            case 2:{
            	system("cls");
				
				//功能2：随机生成数据进行预测
				random_creation(random, ROWS, COLS);				  
				read_data("E:\\compile_test\\data1.txt", random_data, random_labels, ROWS, COLS);   				
				knn(predict_random, train_data, train_labels, TRAIN_ROWS, TRAIN_COLS, ROWS, COLS, random_data, random_labels);
				system("pause");
				break;
			}
			case 3:	{
				system("cls");
				function3(predict, predict_random, test_labels, random_labels);
				system("pause");
				break;
				 }     
			
			default:
                system("cls");
                SetPosition(0,10);
                printf("输入出错，请重新选择操作！\n");
                system("pause");
    
	    
        	
		}
   

    // for (int j = 0; j < TEST_ROWS; j++)
    // {
    //     cout << predict[j] << endl;
    // }


   
    
}
return 0;
//system("pause");
}

//待实现功能：1、系统界面   
//              （功能1）
//              （功能2）
//              （功能3）
//           2、随机选择一条测试数据或随机生成数据，展示其预测值  （功能三）
//              利用第255行  predict(TRAIN_ROWS)与第282行 predict_random(TRAIN_ROWS)实现即可;
