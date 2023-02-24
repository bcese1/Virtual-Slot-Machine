#ifndef Virtualslotmachine_hpp
#define Virtualslotmachine_hpp
#include <string>
#include "Spin.hpp"

class Virtualslotmachine
{
    private:
        //Making slotmachine change
                  // For Debug:
        spin* s1; // Spin #1 on the far left side
        spin* s2; // Spin #2 in the middle
        spin* s3; // Spin #3 on the far right side

    public:
        Virtualslotmachine();
        void reel(); // Spins the reels of the virtual slotmachine
        int pay(); // amount of money going out for combination
        //std::string getS1prev(), gets1(), gets1next(), gets2prev(), gets2(),
       // gets2next(), gets3prev(), gets3();
       // std::string gets3next();
/*      std::string gets1();
        std::string gets2next();
        std::string gets2prev();
        std::string gets2();
        std::string gets2next();
        std::string gets3prev();
        std::string gets3();
        std::string gets3next();
*/

        std::string getS1prev();
        std::string gets1();
        std::string gets1next();
        std::string gets2prev();
        std::string gets2();
        std::string gets2next();
        std::string gets3prev();
        std::string gets3();
        std::string gets3next();
};




#endif


