#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
std::vector<std::vector<double> > group(std::vector<int> p, std::vector<double> c);
double distance(double x, double y);
double center(std::vector<double> p);
bool equal(std::vector<double> a, std::vector<double> b);
std::vector<std::vector<double> > cluster(std::vector<int> int_vec, int k);
double sum(std::vector<double> p);
int min(std::vector<double> p);

template<class T>
void print_vec(std::vector<T> int_vec)
{
    for(int i=0;i<int_vec.size();i++)
        std::cout<<int_vec[i]<<"\t";
    std::cout<<std::endl;
}

int main(int argc, char const *argv[])
{
	int data[] = { 1, 20, 89, 22, 72, 2,39, 3,56,86, 5, 93,13, 15, 18, 73, 79, 81, 25, 38, 43, 83,48, 52, 59,92,84,95,87 };
	std::vector<int> p_int(data, data + sizeof(data) / sizeof(int));
	int k = 5;
	std::vector<std::vector<double> > g = cluster(p_int, k);
    for(int i=0;i<g.size();i++)
    {
        print_vec<double>(g[i]);
    }
	return 0;
}

std::vector<std::vector<double> > cluster(std::vector<int> int_vec, int k)
{
	std::vector<double> core;//存储旧的聚类中心
	core.resize(5);//
	std::vector<double> core_new;
	core_new.resize(5);//存储新的聚类中心

	std::vector<std::vector<double> > g;

	//经典的聚类算法是随机选择k个元素作为聚类中心，这里选择前十个元素作为聚类中心
	for (int i = 0; i < k; i++)
	{
		core[i] = int_vec[i];
	}

	while (true)
	{
		g = group(int_vec, core);
		for (int i = 0; i<g.size(); i++)
		{
			core_new[i] = center(g[i]);
		}
        
		if (!equal(core_new, core))
		{
			core = core_new;
		}
		else
			break;
	}
	return g;

}

double center(std::vector<double> p)
{
	return sum(p) / p.size();
}

std::vector<std::vector<double> > group(std::vector<int> p, std::vector<double> c)
{
	//中间变量用来分组标记
	std::vector<double> gi;
	gi.resize(p.size());//考察每一个点与聚类中心的距离
	for (int i = 0; i < p.size(); i++)
	{
		std::vector<double> d;
		d.resize(c.size());//
		for (int j = 0; j < c.size(); j++)
		{
			d[j] = distance(p[i], c[j]);
		}
		int ci = min(d);//找出距离最小的点
		gi[i] = ci;
	}

	//存放分组结果
	std::vector<std::vector<double> > g(5);

	for (int i = 0; i < c.size(); i++)
	{
		int s = 0;
		for (int j = 0; j < gi.size(); j++)
		{
			if (gi[j] == i)
				s++;
		}
		g[i].resize(s);
		s = 0;
		for (int j = 0; j < gi.size(); j++)
		{
			if (gi[j] == i)
			{
				g[i][s] = p[j];
				s++;
			}
		}
	}
	return g;
}

double distance(double x, double y)
{
	double num=x-y;
    return num>0?num:-num;
}

double sum(std::vector<double> p)
{
	double sum = 0;
	for (int i = 0; i < p.size(); i++)
	{
		sum += p[i];
	}
	return sum;
}

int min(std::vector<double> p)
{
	int i = 0;
	double m = p[0];
	for (int j = 1; j < p.size(); j++)
	{
		if (p[j] < m)
		{
			i = j;
			m = p[j];
		}
	}
	return i;
}

bool equal(std::vector<double> a, std::vector<double> b)
{
	if (a.size() != b.size())
		return false;
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] != b[i])
			return false;
	}
	return true;
}