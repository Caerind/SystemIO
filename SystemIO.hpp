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
        /// \brief Used to represent what a data is
        typedef std::map<std::string,std::string> Data;

        /// \brief Test if a data contains a specific element
        /// \param data The data
        /// \param id The id of the element
        /// \return true if the data contains the element
        static bool has(Data const& data, std::string const& id);

        /// \brief Get the string representation of a keyboard key
        /// \param key The keyboard key
        /// \return The string representing the key ("Unknown" if unable to find the key)
        static std::string keyToString(sf::Keyboard::Key const& key);

        /// \brief Get the keyboard key from a string
        /// \param str The string you want to convert
        /// \return The keyboard key (sf::Keyboard::Unknown if unable to convert)
        static sf::Keyboard::Key stringToKey(std::string const& str);

        /// \brief Convert a string to a data (string style : "type=Event&param=1")
        /// \param event The string
        /// \return The data generated
        static Data stringToData(std::string const& event);

        /// \brief Convert an sf::Event to data
        /// \param event The event
        /// \return The data generated
        static Data eventToData(sf::Event const& event);

        /// \brief Convert an sf::Event::EventType to a string representing its type in SystemIO
        /// \param type The SFML event type
        /// \return The SystemIO event type
        static std::string sfGetType(sf::Event::EventType type);

    public:
        /// \brief Ctor
        SystemIO();

        /// \brief Update function. You have to call it every frame
        /// \param dt The delta time since the last frame. Passed to each output as the "dt" element.
        void update(sf::Time dt);

        /// \brief Set the window used to automatically catch events from it. If you do this, you need to not catch events yourself
        /// \param window The SFML window
        void setWindow(sf::Window* window);

        /// \brief Submit a string event (string style: "type=Event&param=1")
        /// \param event String event
        void handleEvent(std::string const& event);

        /// \brief Submit a SFML event
        /// \param event SFML event
        void handleEvent(sf::Event const& event);

        /// \brief Create an input
        /// \param id The input id
        /// \param input The filter of the input
        void createInput(std::string const& id, std::string const& input);

        /// \brief Create an input
        /// \param id The input id
        /// \param input The filter of the input
        void createInput(std::string const& id, bool& input);

        /// \brief Create an input
        /// \param id The input id
        /// \param func The filter of the input
        void createInput(std::string const& id, std::function<bool()> func);

        /// \brief Create an output
        /// \param id The output id
        /// \param func The output function
        void createOutput(std::string const& id, std::function<void(Data const& data)> func);

        /// \brief Remove an input
        /// \param id The input id
        void removeInput(std::string const& id);

        /// \brief Remove an output
        /// \param id The output id
        void removeOutput(std::string const& id);

        void connect(std::string const& inputId, std::string const& outputId);
        void disconnect(std::string const& inputId, std::string const& outputId);

    private:
        /// Add extra data to the input
        Data addData(Data inputData, sf::Time dt);


        bool passFilter(Data const& filterData, Data const& inputData);
        void dataToConnected(std::string const& inputId, Data const& data);

    private:
        sf::Window* mWindow; ///< Used to automatically catch events

        std::vector<Data> mInputs; ///< Store all the inputs received in a frame

        std::map<std::string,Data> mFilterDatas; ///< Filters that generate an output from an input (using data)
        std::map<std::string,std::function<bool()>> mFilterFunctions; ///< Filters that generate an output from an input (using functions)

        std::map<std::string,std::function<void(Data const& data)>> mOutputs; ///< Outputs

        std::map<std::string,std::vector<std::string>> mConnections; ///< Connections between inputs and outputs
};

#endif // SYSTEMIO_HPP
