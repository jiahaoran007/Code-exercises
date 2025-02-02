#include<iostream>
using namespace std;
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<vector>
#include<algorithm>

#define N 10					//????????????????
#define C 10					//????????
#define T 10					//????????????T=K+LV+1??
#define cross_rate 0.75			//??????
#define muta_rate 0.1			//??????
#define I 200					//????????

//10????????????
double citys_position[C][2] =
{
	{1304,2312},{3639,1315},{4177,2244},{3712,1399},{3488,1535},
	{3326,1556},{3238,1229},{4196,1004},{4312,7900},{4386,570}
};

class Genetic_Algorithm
{
private:
	int i, j;
	int population[N][T];			//N-T,??????
	int it;							//???????????
	//int init_population[N][T];		//N-T,??????
	double F1[N];					//N???????????????????????????
	double F2[N];					//N????????????????????????????
	double R[N];					//N,????????????????????
	double p[N];					//N?????????????????????????????
	int rand_population[N][T];		//N-T,????????
	int cross_population[N][T];		//N-T,??????????
	int muta_population[N][T];		//N-T,??????????
	int mix_population[N][T];		//N-T,??????
public:
	/*??????GA???????????????o*/
	void GA();
	/*??????Initial_Population?????????????????*/
	void Initial_Population();
	/*??????Fitness???????????????????????*/
	double Fitness(int* input_solution);
	/*??distance???????????????????????????????????????????????????*/
	double distance(double* city1, double* city2);
	/*??????Selection??????????????N????????????*/
	void Selection();
	/*??????Crossover??????????????*/
	void Crossover();
	/*??????Order_Crossover??????????OX??????????????????cross_population??*/
	void Order_Crossover(int* father, int* mother, int Z1, int Z2);
	/*??????Mutation?????????????*/
	void Mutation();
	/*??????Best_Solution????????????????????????????????????????????????*/
	void Best_Solution();
	/*??????Mixing_population?????????????????????????
	?????70%????????????20%???????????10%?????????????^*/
	void Mixing_population();
};

int main()
{
	srand((unsigned)time(NULL));
	
	Genetic_Algorithm GA1;
	GA1.GA();


	system("pause");
	return 0;

}
/*??????GA??????????????o*/
void Genetic_Algorithm::GA()
{
	if (N % 2 != 0)
	{
		cout << "???N?????2???????" << endl;
	}
	/*???????????Initial_Population?????????????*/
	Initial_Population();
	/*???????????Fitness?????????????????????????*/
	for (i = 0; i < N; i++)
	{
		F1[i] = Fitness(population[i]);
	}
	/*????*/
	for (it = 0; it < I/2; it++)
	{
		/*???????????Selection??????????N????????????*/
		Selection();
		/*???????????Crossover??????????*/
		Crossover();
		/*???????????Mutation?????????*/
		Mutation();
		/*???????????Fitness??????????????????????????*/
		for (i = 0; i < N; i++)
		{
			F2[i] = Fitness(muta_population[i]);
		}
		/*???????????Best_Solution?????????????????????????????????????????????*/
		Best_Solution();
		/*??????????Mixing_population?????????????????????
		?????70%????????????20%???????????10%?????????????^*/
		Mixing_population();
	}


	
    
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;cout << "?????????????????" << endl;
    cout << "??????????????" << endl;
    Best_Solution();
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
	
    Initial_Population();
	/*???????????Fitness?????????????????????????*/
	for (i = 0; i < N; i++)
	{
		F1[i] = Fitness(population[i]);
	}
    	for (it = 0; it < I/2; it++)
	{
		/*???????????Selection??????????N????????????*/
		Selection();
		/*???????????Crossover??????????*/
		Crossover();
		/*???????????Mutation?????????*/
		Mutation();
		/*???????????Fitness??????????????????????????*/
		for (i = 0; i < N; i++)
		{
			F2[i] = Fitness(muta_population[i]);
		}
		/*???????????Best_Solution?????????????????????????????????????????????*/
		Best_Solution();
		/*??????????Mixing_population?????????????????????
		?????70%????????????20%???????????10%?????????????^*/
		Mixing_population();
	}


}
/*??????Initial_Population????????????????*/
void Genetic_Algorithm::Initial_Population()
{
	//?????????????
	vector<int> temp_city;
	for (int i = 0; i < C; i++)
	{
		temp_city.push_back(i + 1);
	}
	//???????????????
	for (i = 0; i < N; i++)
	{
		random_shuffle(temp_city.begin(), temp_city.end());
		for (int j = 0; j < temp_city.size(); j++)
		{
			population[i][j] = temp_city[j];
		}
	}
	cout << "init_population:" << endl;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < T; j++)
		{
			cout << population[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}
/*??Fitness??????????????????????????*/
double Genetic_Algorithm::Fitness(int* input_solution)
{
	//?????????????
	double cost = 0;
	//??????????????????????????
	for (int j = 0; j < C - 1; j++)
	{
		//???????????????????????????????????????
		cost += distance(citys_position[input_solution[j] - 1], citys_position[input_solution[j + 1] - 1]);
	}
	//??????????????????????
	cost += distance(citys_position[input_solution[C - 1] - 1], citys_position[input_solution[0] - 1]);

	return cost;
}
/*??distance???????????????????????????????????????????????????*/
double Genetic_Algorithm::distance(double* city1, double* city2)
{
	/*???????????????????*/
	double x1 = city1[0];			//????1??????
	double y1 = city1[1];
	double x2 = city2[0];
	double y2 = city2[1];			//????2??????
	double dist = pow((pow((x1 - x2), 2) + pow((y1 - y2), 2)), 0.5);

	return dist;					//????????
}
/*??????Selection?????????????N????????????*/
void Genetic_Algorithm::Selection()
{
	double sum = 0;
	double SUM = 0;
	//????????????
	for (i = 0; i < N; i++)
	{
		R[i] = 1 / (F1[i]);
		SUM += R[i];
	}
	//????????????????
	for (i = 0; i < N; i++)
	{
		R[i] = 1 / (F1[i]);
		sum += R[i];
		p[i] = sum / SUM;
	}
	//??????????????????
	for (i = 0; i < N; i++)
	{
		double r = { 0.0 };
		r = (double)rand() / RAND_MAX;
		for (int k = 0; k < N; k++)
		{
			if (r <= p[k])
			{
				for (j = 0; j < T; j++)
				{
					rand_population[i][j] = population[k][j];
				}
				break;
			}
		}
	}
}
/*??????Crossover?????????????*/
void Genetic_Algorithm::Crossover()
{
	int chromoN1, chromoN2;
	int Z1 = 0;                 //???????????cross_population???????
	int Z2 = 1;                 //???????????cross_population???????
	int father[T];				//T,???????
	int mother[T];				//T,???????
	//????N/2??
	for (i = 0; i < N / 2; i++)
	{
		//??????
		chromoN1 = rand() % N;
		chromoN2 = rand() % N;
		while (chromoN1 == chromoN2)
		{
			chromoN2 = rand() % N;//????????????????
		}
		for (j = 0; j < T; j++)
		{
			father[j] = rand_population[chromoN1][j];	//??
			mother[j] = rand_population[chromoN2][j];	//?
		}
		//???????
		double r = (double)rand() / RAND_MAX;
		if (r <= cross_rate)
		{
			//????????Order_Crossover??????OX??????????????????cross_population
			Order_Crossover(father, mother, Z1, Z2);
			Z1 += 2;//???cross_population[Z1][]???????????????
			Z2 += 2;//???cross_population[Z2][]???????????????
		}
		else
		{
			//??????
			for (j = 0; j < T; j++)
			{
				cross_population[Z1][j] = father[j];
				cross_population[Z2][j] = mother[j];
			}
			Z1 += 2;//???cross_population[Z1][]???????????????
			Z2 += 2;//???cross_population[Z2][]???????????????
		}
	}

}
/*??????Order_Crossover?????????OX????????????????cross_population??*/
void Genetic_Algorithm::Order_Crossover(int* father, int* mother, int Z1, int Z2)
{
	int cut_point1, cut_point2;
	int child_indiv1[T] = { 0 };	//T?????????1
	int child_indiv2[T] = { 0 };	//T?????????2
	//?????????????
	cut_point1 = rand() % (T - 1);	//cutpoint[5]={0,1..T-3}
	cut_point2 = rand() % T;		//cutpoint[5]={0,1,2..T-2}
	
	while (cut_point1 >= cut_point2)
	{
		cut_point2 = rand() % T;	//cut_point2>cut_point1
	}
	/*
	cout << "cut_point1:" << cut_point1 << "  cut_point2:" << cut_point2 << endl;
	cout << "father:";
	for (j = 0; j < T; j++)
	{
		cout << father[j] << " ";
	}
	cout << endl;
	cout << "mother:";
	for (j = 0; j < T; j++)
	{
		cout << mother[j] << " ";
	}
	cout << endl;
	*/
	//??????????????????????
	for (int x = cut_point1; x <= cut_point2; x++)
	{
		child_indiv1[x] = father[x];		 //???1??????????????
		child_indiv2[x] = mother[x];		 //???2?????????????
	}
	/*??????????????????*/
	if (cut_point1 != 0)
	{
		//????????1???????????
		int index1 = 0;							 //???1??????
		for (int y = 0; y < T; y++)				 //???????????
		{
			bool bt = true;
			for (int z = cut_point1; z <= cut_point2; z++)
			{
				//????????????????
				if (mother[y] == child_indiv1[z])
				{
					bt = false;					 //???bool?????????????????
					//??????????????????for?????????????????bt=false?????????????????
					break;
				}
			}
			//?????????????bool???????????????????????????
			if (bt == true)
			{
				child_indiv1[index1] = mother[y];//???????????1
				index1 += 1;					 //????????????????
				//?????????????????????????????????????
				if (index1 == cut_point1)
				{
					//????????????????????????????????????
					if (cut_point2 != T - 1)
					{
						index1 = cut_point2 + 1;
					}
					//??????????????????????????
					else
					{
						break;
					}
				}
			}
		}
		//????????2???????????
		int index2 = 0;							 //???2??????
		for (int y = 0; y < T; y++)				 //????????????
		{
			bool bt = true;
			for (int z = cut_point1; z <= cut_point2; z++)
			{
				//????????????????
				if (father[y] == child_indiv2[z])
				{
					bt = false;					 //???bool?????????????????
					//??????????????????for?????????????????bt=false?????????????????
					break;
				}
			}
			//?????????????bool???????????????????????????
			if (bt == true)
			{
				child_indiv2[index2] = father[y];//????????????2
				index2 += 1;					 //????????????????
				//?????????????????????????????????????
				if (index2 == cut_point1)
				{
					//????????????????????????????????????
					if (cut_point2 != T - 1)
					{
						index2 = cut_point2 + 1;
					}
					//??????????????????????????
					else
					{
						break;
					}
				}
			}
		}
		//?????????????????cross_population
		for (j = 0; j < T; j++)
		{
			cross_population[Z1][j] = child_indiv1[j];
			cross_population[Z2][j] = child_indiv2[j];
		}
		/*
		cout << "child1:";
		for (j = 0; j < T; j++)
		{
			cout << child_indiv1[j] << "  ";
		}
		cout << endl;
		cout << "child2:";
		for (j = 0; j < T; j++)
		{
			cout << child_indiv2[j] << "  ";
		}
		cout << endl;
		*/
	}
	/*??????????????*/
	else
	{
		/*??????????????????????????????????????*/
		if (cut_point2 == T - 1)
		{
			//???????????????cross_population
			for (j = 0; j < T; j++)
			{
				cross_population[Z1][j] = father[j];
				cross_population[Z2][j] = mother[j];
			}
		}
		/*??????????????????*/
		else
		{
			//????????1??????????
			int index1 = cut_point2 + 1;			 //???1??????
			for (int y = 0; y < T; y++)				 //???????????
			{
				bool bt = true;
				for (int z = cut_point1; z <= cut_point2; z++)
				{
					//????????????????
					if (mother[y] == child_indiv1[z])
					{
						bt = false;					 //???bool?????????????????
						//??????????????????for?????????????????bt=false?????????????????
						break;
					}
				}
				//?????????????bool???????????????????????????
				if (bt == true)
				{
					child_indiv1[index1] = mother[y];//???????????1
					index1 += 1;					 //????????????????
					/*?????????????????*/
					if (index1 != T)
					{
						index1 += 0;	
					}
					/*????????????????????????*/
					else
					{
						break;
					}
				}
			}
			//????????2???????????
			int index2 = cut_point2 + 1;			 //???2??????
			for (int y = 0; y < T; y++)				 //????????????
			{
				bool bt = true;
				for (int z = cut_point1; z <= cut_point2; z++)
				{
					//????????????????
					if (father[y] == child_indiv2[z])
					{
						bt = false;					 //???bool?????????????????
						//??????????????????for?????????????????bt=false?????????????????
						break;
					}
				}
				//?????????????bool???????????????????????????
				if (bt == true)
				{
					child_indiv2[index2] = father[y];//????????????2
					index2 += 1;					 //????????????????
					/*?????????????????*/
					if (index2 != T)
					{
						index2 += 0;
					}
					/*????????????????????????*/
					else
					{
						break;
					}
				}
			}
			//?????????????????cross_population
			for (j = 0; j < T; j++)
			{
				cross_population[Z1][j] = child_indiv1[j];
				cross_population[Z2][j] = child_indiv2[j];
			}
			/*
			cout << "child1:";
			for (j = 0; j < T; j++)
			{
				cout << child_indiv1[j] << "  ";
			}
			cout << endl;
			cout << "child2:";
			for (j = 0; j < T; j++)
			{
				cout << child_indiv2[j] << "  ";
			}
			cout << endl;
			*/
		}
	}
	
}
/*??????Mutation????????????*/
void Genetic_Algorithm::Mutation()
{
	//?????????????????????
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < T; j++)
		{
			muta_population[i][j] = cross_population[i][j];
		}
	}
	//?????????
	int point1, point2;					//?????
	for (i = 0; i < N; i++)
	{
		double r = { 0.0 };
		r = (double)rand() / RAND_MAX;	//????????????
		//????
		if (r <= muta_rate)
		{
			point1 = rand() % T;
			point2 = rand() % T;
			while (point1 == point2)
			{
				point2 = rand() % T;	//???????????
			}
			swap(muta_population[i][point1], muta_population[i][point2]);
		}
	}
}
/*??????Best_Solution????????????????????????????????????????????????*/
void Genetic_Algorithm::Best_Solution()
{
	int big_population[N + N][T];			//???population??muta_population
	double big_fitness[N + N];				//???population??muta_population??????
	//?????population??muta_population
	for (i = 0; i < (N + N); i++)
	{
		if (i < N)
		{
			for (j = 0; j < T; j++)
			{
				big_population[i][j] = population[i][j];
			}
			big_fitness[i] = F1[i];
		}
		else
		{
			for (j = 0; j < T; j++)
			{
				big_population[i][j] = muta_population[i - N][j];
			}
			big_fitness[i] = F2[i - N];
		}
	}
	//?????big_population??????????????
	int min_index = 0;
	int min_value = big_fitness[0];
	int k;
	for (k = 0; k < (N + N); k++)
	{
		if (big_fitness[k] < min_value)
		{
			min_value = big_fitness[k];
			min_index = k;
		}
	}
	if (min_index < N)
	{
		cout << "??" << it << "????????????????????????" << endl;
	}
	else
	{
		cout << "??" << it << "?????????????????????????" << endl;
	}
	for (j = 0; j < T; j++)
	{
		cout << big_population[min_index][j] << "??>";
	}
	cout << big_population[min_index][0] << endl;
	cout << "???????" << big_fitness[min_index] << endl;

}
/*??????Mixing_population?????????????????????????
	?????70%????????????20%???????????10%?????????????^*/
void Genetic_Algorithm::Mixing_population()
{
	int muta_num = round(0.7*N);					//??????????????	
	int init_num = round(0.2*N);					//?????????????
	int gnew_num = N - muta_num - init_num;			//?????????????
	int mix_index = 0;								//????????????
	double F1_copy[N];								//????F1[]
	copy(F1, F1 + N, F1_copy);
	double F2_copy[N];
	copy(F2, F2 + N, F2_copy);						//????F2[]
	double F3[N];									//???mix_popualtion[][]??????

	/*??1???????????????????*/
	//??????????????????
	double sort_F1[N];								//???F1[]??????
	int sort_F1_preindex[N];						//???temp_F1[]?????????????
	for (i = 0; i < N; i++)
	{
		sort_F1[i] = F1[i];//?????
	}
	//????????????
	sort(sort_F1, sort_F1 + N);
	//???????????????????????????????
	for (i = 0; i < N; i++)
	{
		//find()?????????????????????????????????????????
		sort_F1_preindex[i] = (find(F1_copy, F1_copy + N, sort_F1[i]) - F1_copy);
		//??????????????
		F1_copy[sort_F1_preindex[i]] = 0;
	}
	/*
	for (i = 0; i < N; i++)
	{
		cout << sort_F1_preindex[i] << "  ";
	}
	cout << endl;
	*/
	//???????????????????????mix_population
	for (i = 0; i < init_num; i++)
	{
		//???????
		for (j = 0; j < T; j++)
		{
			mix_population[mix_index][j] = population[sort_F1_preindex[i]][j];
		}
		//??????????????
		F3[mix_index] = F1[sort_F1_preindex[i]];
		//???????????????
		mix_index += 1;
	}
	/*??2????????????????????*/
	//??????????????????
	double sort_F2[N];								//????????????????F2[]
	int sort_F2_preindex[N];						//???temp_F2[]?????????????
	for (i = 0; i < N; i++)
	{
		sort_F2[i] = F2[i];
	}
	sort(sort_F2, sort_F2 + N);						//????????????
	//???????????????????????????????
	for (i = 0; i < N; i++)
	{
		sort_F2_preindex[i] = (find(F2_copy, F2_copy + N, sort_F2[i]) - F2_copy);
		//??????????????
		F2_copy[sort_F2_preindex[i]] = 0;
	}
	/*
	for (i = 0; i < N; i++)
	{
		cout << sort_F2_preindex[i] << "  ";
	}
	cout << endl;
	*/
	//???????????????????????mix_population
	for (i = 0; i < muta_num; i++)
	{
		//???????
		for (j = 0; j < T; j++)
		{
			mix_population[mix_index][j] = muta_population[sort_F2_preindex[i]][j];
		}
		//??????????????
		F3[mix_index] = F2[sort_F2_preindex[i]];
		//???????????????
		mix_index += 1;
	}
	/*??3????????????????????????*/
	//?????????????
	int temp_city[C];
	for (int i = 0; i < C; i++)
	{
		temp_city[i] = (i + 1);
	}
	//???????????????
	for (i = 0; i < gnew_num; i++)
	{
		random_shuffle(temp_city, temp_city + C);
		for (j = 0; j < C; j++)
		{
			mix_population[mix_index][j] = temp_city[j];
		}
		F3[mix_index] = Fitness(temp_city);
		mix_index += 1;
	}
	/*??4????mix_population[][]?????population[][]
		   ??F3[]?????F1[]*/
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < T; j++)
		{
			population[i][j] = mix_population[i][j];
		}
		F1[i] = F3[i];
	}
	cout << "mix_population:" << endl;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < T; j++)
		{
			cout << population[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;


}