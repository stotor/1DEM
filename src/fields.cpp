#include <vector>
#include "fields.hpp"

// Initialize EM fields
void initialize_fields(std::vector<double> e_x, std::vector<double> e_y, std::vector<double> b_z, std::vector<double> j_x,
		       std::vector<double> j_y, int n_g)
{
  // EM wave
  // int mode = 4;
  // for (int i = 0; i < n_g; i++) {
  //   e_x[i] = 0.0;
  //   e_y[i] = cos(double(mode) * 2.0 * PI * (double(i) / double(n_g)));
  //   b_z[i] = cos(double(mode) * 2.0 * PI * (double(i) / double(n_g)));
  //   // BELOW FOR TESTING EM WAVE
  //   j_x[i] = 0.0;
  //   j_y[i] = 0.0;
  // }
  // Zero
  for (int i = 0; i < n_g; i++) {
    e_x[i] = 0.0;
    e_y[i] = 0.0;
    b_z[i] = 0.0;
    j_x[i] = 0.0;
    j_y[i] = 0.0;
  }
};

////////////////////////////////////////////////////////////////
// Fields
void save_old_values(std::vector<double> &array, std::vector<double> &array_old,
		     int n_values)
{
  for (int i = 0; i < n_values; i++) {
    array_old[i] = array[i];
  }
  return;
};

void advance_b_z(std::vector<double> &b_z, std::vector<double> &e_y, double dt, 
		 double dx, int n_g)
{
  for (int i = 0; i < (n_g - 1); i++) {
    b_z[i] = b_z[i] - (dt / dx) * (e_y[i+1] - e_y[i]);
  }
  b_z[n_g-1] = b_z[n_g-1] - (dt / dx) * (e_y[0] - e_y[n_g-1]);
  return;
};

void advance_e_x(std::vector<double> &e_x, std::vector<double> &j_x, double dt, 
		 double dx, int n_g)
{
  for (int i = 0; i < n_g; i++) {
    e_x[i] = e_x[i] - dt * j_x[i];
  }
  return;
};

void advance_e_y(std::vector<double> &e_y, std::vector<double> &b_z, 
		 std::vector<double> &j_y, double dt, 
		 double dx, int n_g)
{
  e_y[0] = e_y[0] - (dt / dx) * (b_z[0] - b_z[n_g-1]) - dt * j_y[0];
  for (int i = 1; i < n_g; i++) {
    e_y[i] = e_y[i] - (dt / dx) * (b_z[i] - b_z[i-1]) - dt * j_y[i];
  }
  return;
};
