// Kumar Dheeraj - VXC7Y1 -
// Chapter 10 - ALL PARTS

#include "std_lib_facilities.h"
                                                                                //drill 1
struct Point {

    double x, y;
    Point(){
		x = y = 0;
	}
	Point(double a, double b){
		x = a;
		y = b;
	}
	void display(Point P){
		cout << "(" << P.x << "," << P.y << ")" << endl;
	}
};
bool compare_vectors(vector<Point> ov,vector<Point> pv){ 
   
    for (int i = 0;i < 7;i++){ 
		if (ov[i].x!= pv[i].x || ov[i].y != pv[i].y)
			return false;
            break;
    }
    return true;
		
}
// driver function
int main(){

    //prompt user for points and store them in vector
    cout << "Please enter seven sets of (x, y) points:\n";
    vector<Point> original_points;
    double x, y;

    for (int i = 0;i < 7;i++){
        cin >>x >> y;                                                                // drill 2
        cout << "(" << x << "," << y << ")" << endl;
        Point p(x,y);
        original_points.push_back(p);
    } 

    cout<< "Displaying the original points" << endl;                                 // drill 3
    for (Point p : original_points)
         p.display(p);
    cout << "\n";

    vector<Point>  processed_points;

    // write points to file
    ofstream f;                                                                     // drill 4
	f.open("mydata.txt");
    if (!f){
        cout << "error can't able to open file, mydata.txt"<<endl;
    }
    else{  
        for (Point i : original_points){
		    f << "("<<i.x << "," << i.y <<")"<< endl;
    	}
    }f.close();

    // read points from file                                            // drill 5
    ifstream f1;
    f1.open("mydata.txt");
    if (!f1){
        cout<<"can't open input file, mydata.txt "<<endl;
    }else{
        double x1, y1;
        string line,s1,s2;
        while (getline(f1, line)){
            int comma= line.find(','), last= line.find(')'), first = line.find('(');
            s1 =line.substr(first+1, comma-1);
            s2 =line.substr(comma+1, last-1);
            x1 = stod(s1);
            y1 = stod(s2);
            Point pp(x1,y1);
            processed_points.push_back(pp);
        }
    
    }
                                                                        // drill 6 
    cout << "\nData from ifstream:\n";
    cout << "Original points : " << endl;
	for (Point op : original_points){
		op.display(op);
	}

	cout <<"Processed points : " << endl;
	for (Point pps : processed_points){
		pps.display(pps);
    }

    // compare vectors
    if (compare_vectors(original_points, processed_points) == true)   // drill 7
		cout << "Congrats, Everything correct";
	else
		cout << "Something's wrong";

	return 0;
}