#ifndef fields_hpp
#define fields_hpp

#include <vector>

void initialize_fields(std::vector<double> e_x, std::vector<double> e_y, std::vector<double> b_z, std::vector<double> j_x,
		       std::vector<double> j_y, int n_g);

void save_old_values(std::vector<double> &array, std::vector<double> &array_old,
		     int n_values);

void advance_b_z(std::vector<double> &b_z, std::vector<double> &e_y, double dt, 
		 double dx, int n_g);

void advance_e_x(std::vector<double> &e_x, std::vector<double> &j_x, double dt, 
		 double dx, int n_g);

void advance_e_y(std::vector<double> &e_y, std::vector<double> &b_z, 
		 std::vector<double> &j_y, double dt, 
		 double dx, int n_g);

#endif /* fields_hpp */
