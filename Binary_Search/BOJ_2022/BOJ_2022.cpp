#include <iostream>
#include <cmath>

using namespace std;

double calculateC(double x, double y, double w)
{
  double h1 = sqrt(x * x - w * w);
  double h2 = sqrt(y * y - w * w);
  return h1 * h2 / (h1 + h2);
}

int main(void)
{
  double x, y, c;
  cin >> x >> y >> c;

  double low, high;
  low = 0;
  high = min(x, y);

  double w;

  while (high - low > 0.0001)
  {
    w = (low + high) / 2.0;

    if (calculateC(x, y, w) >= c)
      low = w;
    else
      high = w;
  }

  cout.precision(3);
  cout << fixed << w << endl;
}