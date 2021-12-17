#include <boost/di.hpp>
namespace di = boost::di;

#include <string>
using namespace std;


// Interface
class IFuel
{
    public:
    virtual ~IFuel() noexcept = default;
    virtual string FillUp() = 0;
    virtual string Status() = 0;
};

// Petrol Fuel Tank implementation of IFuel
class FuelTank : public IFuel
{
    private: 
    bool isFull = false;
    public:
    string FillUp() override { this->isFull = true; return "Filling up!";  }
    string Status() override { return (this->isFull)? "Full" : "Empty"; }
};

// A car that can have diferent types of fuel storage technologie!
class Car
{
    private:
    IFuel &fuel; 

    public:
    Car (IFuel &f):fuel(f){}

    void Run()
    {
        printf("%s\n", fuel.Status().c_str());
        printf("%s\n", fuel.FillUp().c_str());
        printf("%s", fuel.Status().c_str());
    }
};

int main()
{
    const auto carFactory = di::make_injector
            (di::bind<IFuel>().to<FuelTank>());
    
    auto car = carFactory.create<Car>();

    car.Run();

    return 0;
}