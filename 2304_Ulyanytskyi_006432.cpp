#include <iostream>
#include <string>

using namespace std;

class Engine {
private:
    int cylinders;
    double displacement;
    bool engine_running = false;
    bool engine_breakage = false;

public:
    Engine(int cylinders, double displacement) : cylinders(cylinders), displacement(displacement) {}
    
    bool get_engine_running() { return engine_running; }
    bool get_engine_breakage() { return engine_breakage; }
    double get_displacement_number() const { return displacement; }
    int get_cylinders_number() const { return cylinders; }

    void on_off_engine()
    {
        if (!engine_running) {
            engine_running = true;
            cout << "Start engine\n";
        }
        else if (engine_running) {
            engine_running = false;
            cout << "Stop engine\n";
        }
        else {
            engine_breakage = true;
            cout << "Oops! Something broke!\n";
        }
    }
};

class Body {
private:
    string color;
    string body_type;

public:
    Body(string color, string body_type) : color(color), body_type(body_type) {}
    void repaint(string new_color) { color = new_color; }
    string get_body_type() const { return body_type; }
    string get_color() const { return color; }
};

class Car {
private:
    Engine engine;
    Body body;

public:
    Car(int engine_cylinders, double engine_displacement, string body_color, string body_type) : 
        engine(engine_cylinders, engine_displacement), body(body_color, body_type)
    {}

    Car(const Car& other) : 
        engine(other.engine.get_cylinders_number(), other.engine.get_displacement_number()),
        body(other.body.get_color(), other.body.get_body_type())
    {}
    
    string get_color() const { return body.get_color(); }
    void repaint(string new_color) { body.repaint(new_color); }
    void ignition_key() { engine.on_off_engine(); }

    void print_info() const 
    {
        cout << "Engine: " << "Cylinders - " << engine.get_cylinders_number() << ", ";
        cout << "Displacement - " << engine.get_displacement_number() << endl;
        cout << "Body: " << "body type - " << body.get_body_type() << ", ";
        cout << "body color - " << body.get_color() << endl << endl;
    }

    void check_engine()
    {
        bool engine_running_status = engine.get_engine_running();
        if (engine_running_status) {
            if (!engine.get_engine_breakage())
                cout << "The engine has no breakdown\n";                
            else
                cout << "The engine has a breakdown\n";
        }
        else if (!engine_running_status) {
            cout << "It is not possible to perform the test with the engine off! Start engine and repiet.\n";
        }
    }
};

int main() {
    const int CYLINDERS_NUM = 6;
    const double ENGINE_CAPACITY_NUM = 2.4;
    const string BODY_COLOR_1 = "Blue";
    const string BODY_COLOR_2 = "Red";
    const string BODY_TYPE = "Sedan";

    Car car_1(CYLINDERS_NUM, ENGINE_CAPACITY_NUM, BODY_COLOR_1, BODY_TYPE);

    cout << "Car_1:\n";
    car_1.print_info();

    cout << "*try to check engine*\n";
    car_1.check_engine();
    car_1.ignition_key();
    car_1.check_engine();
    car_1.ignition_key();

    cout << "\nCreating car_2 as a copy of car_1\n";
    Car car_2 (car_1);
    
    car_2.repaint(BODY_COLOR_2);
    cout << "Car_2 has been repainted in " << BODY_COLOR_2 << " color\n";

    cout << "\nCar_2:\n";
    car_2.print_info();

    return 0;
}
