#include <boost/asio.hpp>
#include <ctime>
#include <iostream>
#include "prototypes.h"

struct time_t_clock
{
  typedef boost::asio::chrono::steady_clock::duration duration;

  typedef duration::rep rep;

  typedef duration::period period;

  typedef boost::asio::chrono::time_point<time_t_clock> time_point;

  static const bool is_steady = false;

  static time_point now()
  {
    return time_point() + boost::asio::chrono::seconds(std::time(0));
  }
};

struct time_t_wait_traits
{
 
  static time_t_clock::duration to_wait_duration(
      const time_t_clock::duration& d)
  {
    if (d > boost::asio::chrono::seconds(1))
      return d - boost::asio::chrono::seconds(1);
    else if (d > boost::asio::chrono::seconds(0))
      return boost::asio::chrono::milliseconds(10);
    else
      return boost::asio::chrono::seconds(0);
  }

  static time_t_clock::duration to_wait_duration(
      const time_t_clock::time_point& t)
  {
    return to_wait_duration(t - time_t_clock::now());
  }
};

typedef boost::asio::basic_waitable_timer<
  time_t_clock, time_t_wait_traits> time_t_timer;

void handle_timeout(const boost::system::error_code&)
{
  std::cout << "handle_timeout\n";
}



void newDay(bool day) {
    
    bool night{true};
    char ch = 'n';
    
    while (ch != 'z')
    {
        try
            {

                boost::asio::io_context io_context;
                time_t_timer timer(io_context);
                timer.expires_after(boost::asio::chrono::seconds(10));
                std::cout << "Starting new day\n";
                day = true;
                night = false;
                if(day == true) {
                    std::cout << "sun is shining" << std::endl;
                    double air = getAir(day); 
                    std::cout << "frog open glasses";
                    frogLife(air);
                }
                timer.wait();
                
                day = false;
                night = true;

            }
        catch (std::exception& e)
            {
                std::cout << "Exception: " << e.what() << "\n";
            }
            std::cout << "finished is one day";
            std::cout << "if you want end program enter 'z', for new day enter any key" << std::endl;
            std::cin >> ch;

    }
    
}
