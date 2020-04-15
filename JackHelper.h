#pragma once

#include <vector>
#include <string>
#include <jack/jack.h>
#include <jack/midiport.h>
#include <nlohmann/json.hpp>

namespace mck
{
struct Connection
{
    std::string name;
    Connection() : name("") {}
};
void to_json(nlohmann::json &j, const Connection &c);
void from_json(const nlohmann::json &j, Connection &c);

bool GetConnections(jack_client_t *client, jack_port_t *port, std::vector<Connection> &connections);
bool SetConnections(jack_client_t *client, jack_port_t *port, std::vector<Connection> &connections, bool isInput);
} // namespace mck