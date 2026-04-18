#include <iostream>
#include "crow_all.h"
#include "nlohmann/json.hpp"


using json = nlohmann::json;
const int Port=8080;


int main()
{
    crow::SimpleApp app;
    CROW_ROUTE(app, "/hello")
    ([]()
    {
        return "Hello world\n";
    });
    CROW_ROUTE(app, "/add/<int>/<int>")
    ([] (int a, int b) 
    {
        int c { a + b };
        std::string result = "sum is :";
        result += std::to_string(c) + "\n";
        return crow::response(result);
    });
    std::cout << "ok" << std::endl;
    app.port(Port).run();
}