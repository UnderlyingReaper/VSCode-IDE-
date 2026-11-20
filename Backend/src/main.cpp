#include <iostream>
#include "third_party/httplib.h"
#include "third_party/json.hpp"

using json = nlohmann::json;

int main() {
    httplib::Server svr;

    svr.Get("/api/health", [](const httplib::Request&, httplib::Response& res) {
        json response = {{"status", "ok"}, {"service", "code-ide-backend"}};
        res.set_content(response.dump(), "application/json");
    });

    std::cout << "CodeForge server listening on http://localhost:8080\n";
    svr.listen("0.0.0.0", 8080);
    return 0;
}