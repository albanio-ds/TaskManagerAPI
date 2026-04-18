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
    CROW_ROUTE(app, "/api/echo").methods("POST"_method)
    ([](const crow::request& req)
    {
        try
        {
            auto body = json::parse(req.body);
            json response = {{"status", "ok"}, {"received", body}};
            return crow::response(response.dump() + "\n");
        }
        catch (const std::exception& e)
        {
            std::cerr << e.what() << '\n';
            return crow::response{400, "Invalid JSON"};    
        }
    });
    std::cout << "ok" << std::endl;
    app.port(Port).run();
}