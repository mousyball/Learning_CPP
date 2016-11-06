#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

const float coef_u = 3.986 * 100000;
const float PI = 3.1415926535;

inline float getMagnitude(vector<float>&);
inline float innerProduct(vector<float>&, vector<float>&);
inline float getEnergy(float , float);
vector<float> crossProduct(vector<float>&, vector<float>&);

int main(int argc, char** argv)
{
	// Given 2 vector's coefficient
    float r_arr[] = {2615, 15881, 3980};
    float v_arr[] = {-2.767, -0.791, 4.980};
 	// inital arr to vector
    vector<float> r_vec(r_arr, r_arr + 3);
    vector<float> v_vec(v_arr, v_arr + 3);

    /// Homework Task
    // Task 1 : Calculate the vector magnitude.
    cout << "@ Task 1 "<< endl;
    float r_mag = getMagnitude(r_vec);
    float v_mag = getMagnitude(v_vec);
    cout << "R_vec magnitude: " << r_mag << endl;
    cout << "V_vec magnitude: " << v_mag << endl << endl;

    // Task 2 : Calculate the inner product.
    cout << "@ Task 2 "<< endl;
    float r_dot_v = innerProduct(r_vec, v_vec);
    cout << "Inner product of R_vec and V_vec: " << r_dot_v << endl << endl;

    // Task 3 : Calculate the energy.
    // ref : https://en.wikipedia.org/wiki/Semi-major_and_semi-minor_axes
    cout << "@ Task 3 "<< endl;
    float energy = getEnergy(v_mag, r_mag);
    cout << "Energy: " << energy << endl << endl;

    // Task 4 : Calculate the cross product.
    cout << "@ Task 4 "<< endl;
    vector<float> h_vec(3);
    h_vec = crossProduct(r_vec, v_vec);
    cout 	<< "Cross product of R_vec and V_vec: h_vec = " 
			<< h_vec[0] << " i + "
		 	<< h_vec[1] << " j + "
		    << h_vec[2] << " k"
		    << endl << endl;

   	// Task 5 : Calculate the semi-major axis a.
	// ref : https://en.wikipedia.org/wiki/Semi-major_and_semi-minor_axes
	cout << "@ Task 5 "<< endl;
    float coef_a = -coef_u / (2.0*energy);
    cout << "Semi-major axis: a = " << coef_a << endl << endl;

    // Task 6 : Calculate the eccentricity vector e.
    // ref : https://en.wikipedia.org/wiki/Eccentricity_vector
    cout << "@ Task 6 "<< endl;
    vector<float> temp_vec(3);
    vector<float> e_vec(3);
    temp_vec = crossProduct(v_vec, h_vec);
 	e_vec[0] = (temp_vec[0]/coef_u - r_vec[0]/r_mag);
 	e_vec[1] = (temp_vec[1]/coef_u - r_vec[1]/r_mag);
 	e_vec[2] = (temp_vec[2]/coef_u - r_vec[2]/r_mag);
 	cout 	<< "Eccentricity vector: e_vec = " 
			<< e_vec[0] << " i + "
    		<< e_vec[1] << " j + "
    		<< e_vec[2] << " k"
    		<< endl << endl;

    // Task 7 : Calculate the orbit inclination
   	// ref : https://en.wikipedia.org/wiki/Orbital_inclination
   	cout << "@ Task 7 "<< endl;
  	float h_mag = getMagnitude(h_vec);
    float inclination = acos(h_vec[2]/h_mag) * 180.0 / PI;
    cout << "Orbit inclination angle: i = " << inclination << endl << endl;

    // Task 8 : Calculate the longitude of the ascending node, omega
    // ref : https://en.wikipedia.org/wiki/Longitude_of_the_ascending_node
    cout << "@ Task 8 "<< endl;
    float omega;
    float k_arr[] = {0, 0, 1};
    vector<float> k_vec(k_arr, k_arr + 3);
    vector<float> n_vec(3);
    n_vec = crossProduct(k_vec, h_vec);
    cout 	<< "n_vec = " 	
			<< n_vec[0] << " i + "
			<< n_vec[1] << " j + "
			<< n_vec[2] << " k"
			<< endl;

	float n_mag = getMagnitude(n_vec);
	if(n_vec[1] >= 0)	omega = acos(n_vec[0]/n_mag) * 180.0 / PI;
	else				omega = 2 * PI - (acos(n_vec[0]/n_mag) * 180.0 / PI);
	cout << "Longitude of the ascending node: omega = " << omega << endl;

    return 0;
}

inline float getMagnitude(vector<float>& vec) {
	float mag;
	mag = pow(vec[0] * vec[0] + vec[1] * vec[1] + vec[2] * vec[2], 0.5);

	return mag;
}

inline float innerProduct(vector<float>& vec1, vector<float>& vec2) {
	float val;
	val = vec1[0] * vec2[0] + vec1[1] * vec2[1] + vec1[2] * vec2[2];

	return val;
}

inline float getEnergy(float v_mag, float r_mag) {
	float energy;
	energy = (v_mag * v_mag / 2.0) - coef_u / r_mag;

	return energy;
}

vector<float> crossProduct(vector<float>& vec1, vector<float>& vec2) {
	vector<float> out_vec(3);
	out_vec[0] = vec1[1] * vec2[2] - vec2[1] * vec1[2];
	out_vec[1] = vec1[2] * vec2[0] - vec2[2] * vec1[0];
	out_vec[2] = vec1[0] * vec2[1] - vec2[0] * vec1[1];

	return out_vec;
}


