//
// Created by 罗万千 on 2021/1/31.
//

#include <string>
#include <stack>
#include <iostream>
using namespace std;

class BrowserHistory {
public:
    BrowserHistory(string homepage) {
        visit(homepage);
    }

    void visit(string url) {
        m_currentPage = url;
        m_stackX.push(url);
        while (!m_stackY.empty()) {
            m_stackY.pop();
        }
    }

    string back() {
        if (m_stackX.size() <= 1)
            return m_currentPage;

        m_stackY.push(m_stackX.top());
        m_stackX.pop();
        m_currentPage = m_stackX.top();

        return m_currentPage;
    }

    string back(int steps) {
        string res = m_currentPage;
        while (!(m_stackX.size() <= 1) && steps) {
            res = back();
            steps--;
        }
        return res;
    }

    string forward() {
        if (m_stackY.empty())
            return m_currentPage;

        m_stackX.push(m_stackY.top());
        m_stackY.pop();
        m_currentPage = m_stackX.top();
        return m_currentPage;
    }

    string forward(int steps) {
        string res = m_currentPage;
        while (!m_stackY.empty() && steps) {
            res = forward();
            steps--;
        }
        return res;
    }

private:
    stack<string> m_stackX;
    stack<string> m_stackY;
    string m_currentPage;
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */

int main()
{
    BrowserHistory browserHistory("leetcode.com");

    cout << "Visit google.com" << endl;
    browserHistory.visit("google.com");
    cout << "Visit facebook.com" << endl;
    browserHistory.visit("facebook.com");
    cout << "Visit youtube.com" << endl;
    browserHistory.visit("youtube.com");

    cout << "Back 1, Current Page: " << browserHistory.back(1) << endl;
    cout << "Back 1, Current Page: " << browserHistory.back(1) << endl;
    cout << "Forward 1, Current Page: " << browserHistory.forward(1) << endl;

    cout << "Visit linkedin.com" << endl;
    browserHistory.visit("linkedin.com");

    cout << "Forward 2, Current Page: " << browserHistory.forward(2) << endl;
    cout << "Back 2, Current Page: " << browserHistory.back(2) << endl;
    cout << "Back 7, Current Page: " << browserHistory.back(7) << endl;

    return 0;
}