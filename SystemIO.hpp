#ifndef SYSTEMIO_HPP
#define SYSTEMIO_HPP

#include <string>
#include <map>
#include <vector>
#include <sstream>
#include <iostream>
#include <functional>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

class SystemIO
{
    public:
        typedef std::map<std::string,std::string> Data;

        static bool has(Data const& data, std::string const& id);

        static std::string keyToString(sf::Keyboard::Key const& key);
        static sf::Keyboard::Key stringToKey(std::string const& str);

    public:
        SystemIO();

        void update(sf::Time dt);

        void setWindow(sf::Window* window);

        void handleEvent(std::string const& event);
        void handleEvent(sf::Event const& event);

        void createInput(std::string const& id, std::string const& input);
        void createInput(std::string const& id, bool& input);
        void createInput(std::string const& id, std::function<bool()> func);
        void createOutput(std::string const& id, std::function<void(Data const& data)> func);

        void connect(std::string const& inputId, std::string const& outputId);
        void disconnect(std::string const& inputId, std::string const& outputId);

    private:
        Data stringToData(std::string const& event);
        Data eventToData(sf::Event const& event);
        std::string sfGetType(sf::Event::EventType type);

        bool passFilter(Data const& filterData, Data const& inputData);
        Data addData(Data inputData, sf::Time dt);
        void dataToConnected(std::string const& inputId, Data const& data);

    private:
        sf::Window* mWindow;

        std::vector<Data> mInputs;

        std::map<std::string,Data> mFilters;
        std::map<std::string,std::function<bool()>> mFilterBools;

        std::map<std::string,std::function<void(Data const& data)>> mOutputs;

        std::map<std::string,std::vector<std::string>> mConnections;
};

#endif // SYSTEMIO_HPP
