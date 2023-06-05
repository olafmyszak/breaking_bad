#include <iostream>

using namespace std;

const double PI = 3.1415;

double butelka(double cm)
{
    return 10 - (cm - 2) * (cm - 2);
}

double volume(double a, double b)
{
	double f = butelka((a+b)/2);
	return (b-a) * f * f;
}


int main()
{
	std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);

    unsigned int max_volume;
    double filled_volume;

    {
        unsigned int x, y, z;
        cin >> x >> y >> z;

        max_volume = x * y * z;
    }

    {
        double fill_level;
        cin >> fill_level;

        filled_volume = max_volume * fill_level;
    }

    unsigned int n;
    cin>>n;

    for(unsigned int i=1; i<=n; ++i)
    {
        double x;
        cin>>x;

        filled_volume += PI * volume(0, x);

        if(filled_volume > max_volume)
        {
            cout<<i;
            return 0;
        }
    }

    cout<<"NIE";

    return 0;
}