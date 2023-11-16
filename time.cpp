#include <iostream>

class Time {

public:
    // Constructor
    Time(int hh = 0, int mm = 0, int ss = 0) {
        m_hh = hh;
        m_mm = mm;
        m_ss = ss;
    }

    // Class methods

    void setTime() {
        do {
            std::cout << "Set time (hh:mm:ss): " << '\n';
            std::cout << "hh: ";
            std::cin >> m_hh;
            std::cout << "mm: ";
            std::cin >> m_mm;
            std::cout << "ss: ";
            std::cin >> m_ss;

            if (m_hh < 0 || m_hh > 23)
                std::cout << "Hours value is out of range!";
            else if (m_mm < 0 || m_mm > 59)
                std::cout << "Minutes value is out of range!";
            else if (m_ss < 0 || m_ss > 59)
                std::cout << "Seconds value is out of range!";
        }
        while (m_hh < 0 || m_hh > 23 ||
               m_mm < 0 || m_mm > 59 ||
               m_ss < 0 || m_ss > 59);
    }

    void showTime() {
        std::cout << "Current time is ";
        std::cout << m_hh / 10 << m_hh % 10 << ":" << m_mm / 10 << m_mm % 10 << ":" << m_ss / 10 << m_ss % 10 << '\n';
    }

    void setHours() {
        std::cout << "Set hours: ";
        do {
            std::cin >> m_hh;
            if (m_hh < 0 || m_hh > 23)
                std::cout << "Invalid value! Set hour: ";
        }
        while (m_hh < 0 || m_hh > 23);
    }

    void setMinutes() {
        std::cout << "Set minutes: ";
        do {
            std::cin >> m_mm;
            if (m_mm < 0 || m_mm > 59)
                std::cout << "Invalid value! Set minutes: ";
        }
        while (m_mm < 0 || m_mm > 59);
    }

    void setSeconds() {
        std::cout << "Set seconds: ";
        do {
            std::cin >> m_ss;
            if (m_ss < 0 || m_ss > 59)
                std::cout << "Invalid value! Set seconds: ";
        }
        while (m_ss < 0 || m_ss > 59);
    }

    void changeHours() {
        int ch_value = 0;
        std::cout << "Enter number of hours: ";
        std::cin >> ch_value;
        m_hh = (m_hh + ch_value + 24) % 24;
    }

    void changeMinutes() {
        int ch_value = 0;
        std::cout << "Enter number of minutes: ";
        std::cin >> ch_value;
        m_mm = (m_mm + ch_value + 60) % 60;
    }

    void changeSeconds() {
        int ch_value = 0;
        std::cout << "Enter number of seconds: ";
        std::cin >> ch_value;
        m_ss = (m_ss + ch_value + 60) % 60;
    }

private:
    // Class fields
    int m_hh;
    int m_mm;
    int m_ss;

};


int main() {

    Time time;

    int op = 0;
    enum setTimeOp {end, sh_t, set_t, set_hh, set_mm, set_ss, ch_hh, ch_mm, ch_ss};

    std::cout << "Choose option:" << '\n';
    std::cout << "1 - Show time" << '\n';
    std::cout << "2 - Set time" << '\n';
    std::cout << "3 - Set hours" << '\n';
    std::cout << "4 - Set minutes" << '\n';
    std::cout << "5 - Set seconds" << '\n';
    std::cout << "6 - Change hours" << '\n';
    std::cout << "7 - Change minutes" << '\n';
    std::cout << "8 - Change seconds" << '\n';
    std::cout << "0 - End" << '\n';

    do {
        do {
            std::cout << '\n' << "Choose option: ";
            std::cin >> op;
            if (op < 0 || op > 8)
                std::cout << "There is no such option!" << '\n';
        }
        while (op < 0 || op > 8);

        switch (op) {

            case sh_t:
                time.showTime();
                break;

            case set_t:
                time.setTime();
                break;

            case set_hh:
                time.setHours();
                break;

            case set_mm:
                time.setMinutes();
                break;

            case set_ss:
                time.setSeconds();
                break;

            case ch_hh:
                time.changeHours();
                time.showTime();
                break;

            case ch_mm:
                time.changeMinutes();
                time.showTime();
                break;

            case ch_ss:
                time.changeSeconds();
                time.showTime();
                break;

            case end:
                std::cout << "Done!" << '\n';
                break;

            default:
                break;
        }
    }

    while (op != 0);

    return 0;
}
