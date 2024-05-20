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
#define POS_X1 35       //1���˵�ҳ����һ�����й��������ʼλ�õ�x����ֵ��2������֮�������ʾ����X����ֵ
#define POS_X2 40       //����ģ�����ʾ�������X����ֵ
#define POS_X3 50       //��һ�Σ���������ģ���������ݶ���ģ�鹦��������������ܣ���ʾ��ϵͳ������ѧ���ɼ���Ϣ���������롱����ʼλ�õ�X����ֵ
#define POS_X4 65       //�˵�ҳ���ڶ������й��������ʼλ�õ�x����ֵ��
#define POS_Y 3  
using namespace std;

const int K = 8; // ����kֵΪ5

//����ѵ���������������
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
        //cout << "���ݶ���ɹ� " << file_name << endl;
    }
    else
    {
        //cerr << "�޷����ļ� " << file_name << endl;
        exit(1);
    }
}

//�������rows �� cols ��С�����飬ģ���������
void random_creation(vector<vector<float>> &random, int rows, int cols)
{
    // random_device rd;  // ��ȷ������������������������������ 
    // mt19937 gen(rd()); // ÷ɭ��ת�㷨 32-bit �ռ������������
    // uniform_real_distribution<float> dis(15.0, 20.0);  // ���ȷֲ���[15.0, 20.0)��Χ�ڵĵ����������������

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
        cout << "������д��data1.txt" << endl;
    }
    else {
        cerr << "�޷���data1.txt" << endl;
    }
}

//knn�㷨���з���
void knn(vector<float>& predict, vector<vector<double>>& train_data, vector<float>& train_labels, int train_num_rows, int train_num_cols, int test_num_rows, int test_num_cols, vector<vector<double>>& test_data, vector<float>& test_labels)
{
        // �Բ������ݽ��з���
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
        sort(distances.begin(), distances.end()); // �������С��������
        // �ҳ�ǰK������ڵı�ǩ��������ͶƱ
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
    cout << "���������з���Ԥ��Ĺ��ƣ�" << correct_count << "��" << endl;
    cout << "׼ȷ��: " << accuracy << endl;
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
    int option;                         //�����û�����Ĳ������ŵı���
    int i,j;
    SetPosition(POS_X3,posy);
    printf("������emo����knn�㷨��\n");      //���ϵͳ��
    //���ϵͳ���͹���˵��֮������ж̺���
    for(i=0; i<2; i++)
    {
        SetPosition(POS_X1, ++posy);
        for(j=0; j<55; j++)
        {
            printf("-");
        }
    }
    //���ϵͳ֧�ֵĹ��ܺͶ�Ӧ�Ĺ��ܴ���
    SetPosition(POS_X1,++posy);
    printf("1.ԭʼ����Ԥ��");
    SetPosition(POS_X4,posy);
    printf("2.�������Ԥ��");
    SetPosition(POS_X1,posy+=2);
    printf("3.����Ԥ��");
    
    printf("0.�˳�");
    //���ϵͳ֧�ֵĹ�����������ʾ��֮������ж̺���
    for(i=0; i<2; i++)
    {
        SetPosition(POS_X1,++posy);
        for(j=0; j<55; j++)
        {
            printf("-");
        }
    }
    //��ʾ�û�������Ҫִ�еĹ��ܴ���
    SetPosition(POS_X1,++posy);
    printf("��ѡ������Ҫ���еĲ���[0~2]: [  ]\b\b\b");
    scanf("%d",&option);
    return option;
}
void function3(vector<float>& predict,vector<float>& predict_random,vector<float>& test_labels,vector<float>& random_labels)
{
	int n=1;
	int m=1,m1=1;
	cout<<"                           1.ԭʼ����Ԥ��ֵ"<<endl;
	cout<<"                           2.�������Ԥ��ֵ"<<endl;
	cout<<"                           0.�˳�"<<endl;
	 
	while(n!=0)
	{
		cout<<"�������ѯ���������� ";
		cin>>n;
		switch(n)
		{
			case 1:
				{
					while(m!=0)
					{
						cout<<"��������Ҫ��ѯ�����ݵ����";
						cin>>m;
						if(m!=0)
						{
							cout<<"Ԥ��ֵ��"<<predict[m]<<" ��ȷֵ��"<<test_labels[m]<<endl;
						}
																										
					}
					cout<<"�˳���ѯ"<<endl; 
					break;
				}
			case 2:{
				      while(m1!=0)
				      {
				      	cout<<"��������Ҫ��ѯ�����ݵ����";
						cin>>m1;
						if(m1!=0)
						{
							cout<<"Ԥ��ֵ��"<< predict_random[m1]<<" ��ȷֵ��"<<random_labels[m1]<<endl;
						}
						 
					  }
				       cout<<"�˳���ѯ"<<endl; 
				break;
			}
			case 0:
				{
					break; 
				}
			default:
			{
				cout<<"��������"<<endl;
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
    read_data("E:\\compile_test\\train_emtion.txt", train_data, train_labels, TRAIN_ROWS, TRAIN_COLS);//����ѵ������

    // for (int j = 0; j < TRAIN_COLS; ++j)
    // {
    //     cout << train_data[0][j];
    // }
    //cout <<train_labels[1] << endl;

    const int TEST_ROWS = 150;
    const int TEST_COLS = 62;
    vector<vector<double>> test_data(TEST_ROWS, vector<double>(TEST_COLS));
    vector<float> test_labels(TEST_ROWS);
    read_data("E:\\compile_test\\test_emtion.txt", test_data, test_labels, TEST_ROWS, TEST_COLS);//�����������

    //float predict[TEST_ROWS];

    vector<float> predict(TRAIN_ROWS);//��¼ÿ���������ݵ�Ԥ��ֵ����150����������
    const int ROWS = 100;
    const int COLS = 62;
	vector<vector<float>> random(ROWS, vector<float>(COLS));
	vector<vector<double>> random_data(ROWS, vector<double>(COLS));
	vector<float> predict_random(TRAIN_ROWS);////��¼ÿ������������ݵ�Ԥ��ֵ����100����������
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
                printf("�˳�ϵͳ��\n");
                exit(0);
        	case 1:
        		system("cls");
        		 knn(predict, train_data, train_labels, TRAIN_ROWS, TRAIN_COLS, TEST_ROWS, TEST_COLS, test_data, test_labels);//����1���Բ������ݽ���Ԥ��
                 cout << endl;
                 system("pause");
                 break;
            case 2:{
            	system("cls");
				
				//����2������������ݽ���Ԥ��
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
                printf("�������������ѡ�������\n");
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

//��ʵ�ֹ��ܣ�1��ϵͳ����   
//              ������1��
//              ������2��
//              ������3��
//           2�����ѡ��һ���������ݻ�����������ݣ�չʾ��Ԥ��ֵ  ����������
//              ���õ�255��  predict(TRAIN_ROWS)���282�� predict_random(TRAIN_ROWS)ʵ�ּ���;
