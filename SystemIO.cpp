#include "SystemIO.hpp"

bool SystemIO::has(SystemIO::Data const& data, std::string const& id)
{
    return (data.find(id) != data.end());
}

std::string SystemIO::keyToString(sf::Keyboard::Key const& key)
{
    switch (key)
    {
        #define CASE1(identifier) case sf::Keyboard::identifier: return #identifier; break;
        CASE1(Unknown);
		CASE1(A);
		CASE1(B);
		CASE1(C);
		CASE1(D);
		CASE1(E);
		CASE1(F);
		CASE1(G);
		CASE1(H);
		CASE1(I);
		CASE1(J);
		CASE1(K);
		CASE1(L);
		CASE1(M);
		CASE1(N);
		CASE1(O);
		CASE1(P);
		CASE1(Q);
		CASE1(R);
		CASE1(S);
		CASE1(T);
		CASE1(U);
		CASE1(V);
		CASE1(W);
		CASE1(X);
		CASE1(Y);
		CASE1(Z);
		CASE1(Num0);
		CASE1(Num1);
		CASE1(Num2);
		CASE1(Num3);
		CASE1(Num4);
		CASE1(Num5);
		CASE1(Num6);
		CASE1(Num7);
		CASE1(Num8);
		CASE1(Num9);
		CASE1(Escape);
		CASE1(LControl);
		CASE1(LShift);
		CASE1(LAlt);
		CASE1(LSystem);
		CASE1(RControl);
		CASE1(RShift);
		CASE1(RAlt);
		CASE1(RSystem);
		CASE1(Menu);
		CASE1(LBracket);
		CASE1(RBracket);
		CASE1(SemiColon);
		CASE1(Comma);
		CASE1(Period);
		CASE1(Quote);
		CASE1(Slash);
		CASE1(BackSlash);
		CASE1(Tilde);
		CASE1(Equal);
		CASE1(Dash);
		CASE1(Space);
		CASE1(Return);
		CASE1(BackSpace);
		CASE1(Tab);
		CASE1(PageUp);
		CASE1(PageDown);
		CASE1(End);
		CASE1(Home);
		CASE1(Insert);
		CASE1(Delete);
		CASE1(Add);
		CASE1(Subtract);
		CASE1(Multiply);
		CASE1(Divide);
		CASE1(Left);
		CASE1(Right);
		CASE1(Up);
		CASE1(Down);
		CASE1(Numpad0);
		CASE1(Numpad1);
		CASE1(Numpad2);
		CASE1(Numpad3);
		CASE1(Numpad4);
		CASE1(Numpad5);
		CASE1(Numpad6);
		CASE1(Numpad7);
		CASE1(Numpad8);
		CASE1(Numpad9);
		CASE1(F1);
		CASE1(F2);
		CASE1(F3);
		CASE1(F4);
		CASE1(F5);
		CASE1(F6);
		CASE1(F7);
		CASE1(F8);
		CASE1(F9);
		CASE1(F10);
		CASE1(F11);
		CASE1(F12);
		CASE1(F13);
		CASE1(F14);
		CASE1(F15);
		CASE1(Pause);
		default: return "Unknown"; break;
    }
}

sf::Keyboard::Key SystemIO::stringToKey(std::string const& str)
{
    #define CASE3(identifier) if (str == #identifier) { return sf::Keyboard::identifier; }
    CASE3(Unknown);
    CASE3(A);
    CASE3(B);
    CASE3(C);
    CASE3(D);
    CASE3(E);
    CASE3(F);
    CASE3(G);
    CASE3(H);
    CASE3(I);
    CASE3(J);
    CASE3(K);
    CASE3(L);
    CASE3(M);
    CASE3(N);
    CASE3(O);
    CASE3(P);
    CASE3(Q);
    CASE3(R);
    CASE3(S);
    CASE3(T);
    CASE3(U);
    CASE3(V);
    CASE3(W);
    CASE3(X);
    CASE3(Y);
    CASE3(Z);
    CASE3(Num0);
    CASE3(Num1);
    CASE3(Num2);
    CASE3(Num3);
    CASE3(Num4);
    CASE3(Num5);
    CASE3(Num6);
    CASE3(Num7);
    CASE3(Num8);
    CASE3(Num9);
    CASE3(Escape);
    CASE3(LControl);
    CASE3(LShift);
    CASE3(LAlt);
    CASE3(LSystem);
    CASE3(RControl);
    CASE3(RShift);
    CASE3(RAlt);
    CASE3(RSystem);
    CASE3(Menu);
    CASE3(LBracket);
    CASE3(RBracket);
    CASE3(SemiColon);
    CASE3(Comma);
    CASE3(Period);
    CASE3(Quote);
    CASE3(Slash);
    CASE3(BackSlash);
    CASE3(Tilde);
    CASE3(Equal);
    CASE3(Dash);
    CASE3(Space);
    CASE3(Return);
    CASE3(BackSpace);
    CASE3(Tab);
    CASE3(PageUp);
    CASE3(PageDown);
    CASE3(End);
    CASE3(Home);
    CASE3(Insert);
    CASE3(Delete);
    CASE3(Add);
    CASE3(Subtract);
    CASE3(Multiply);
    CASE3(Divide);
    CASE3(Left);
    CASE3(Right);
    CASE3(Up);
    CASE3(Down);
    CASE3(Numpad0);
    CASE3(Numpad1);
    CASE3(Numpad2);
    CASE3(Numpad3);
    CASE3(Numpad4);
    CASE3(Numpad5);
    CASE3(Numpad6);
    CASE3(Numpad7);
    CASE3(Numpad8);
    CASE3(Numpad9);
    CASE3(F1);
    CASE3(F2);
    CASE3(F3);
    CASE3(F4);
    CASE3(F5);
    CASE3(F6);
    CASE3(F7);
    CASE3(F8);
    CASE3(F9);
    CASE3(F10);
    CASE3(F11);
    CASE3(F12);
    CASE3(F13);
    CASE3(F14);
    CASE3(F15);
    CASE3(Pause);
    return sf::Keyboard::KeyCount;
}

SystemIO::SystemIO() : mWindow(nullptr)
{
}

void SystemIO::update(sf::Time dt)
{
    if (mWindow != nullptr)
    {
        sf::Event event;
        while (mWindow->pollEvent(event))
        {
            handleEvent(event);
        }
    }

    // For each input
    for (std::size_t i = 0; i < mInputs.size(); i++)
    {
        // For each filter
        for (auto filter = mFilters.begin(); filter != mFilters.end(); filter++)
        {
            // If an input pass filter
            if (passFilter(filter->second,mInputs[i]))
            {
                dataToConnected(filter->first,addData(mInputs[i],dt));
            }
        }
    }
    mInputs.clear();

    // For each realtime
    for (auto realtime = mFilterBools.begin(); realtime != mFilterBools.end(); realtime++)
    {
        if (realtime->second)
        {
            if (realtime->second())
            {
                Data d;
                d["type"] = "io::Realtime";
                d["realtimeId"] = realtime->first;
                dataToConnected(realtime->first,addData(d,dt));
            }
        }
    }
}

void SystemIO::handleEvent(std::string const& event)
{
    mInputs.push_back(stringToData(event));
}

void SystemIO::handleEvent(sf::Event const& event)
{
    mInputs.push_back(eventToData(event));
}

void SystemIO::createInput(std::string const& id, std::string const& input)
{
    mFilters[id] = stringToData(input);

    // Remove input with similar name in bools
    auto itr = mFilterBools.find(id);
    if (itr != mFilterBools.end())
    {
        mFilterBools.erase(itr);
    }
}

void SystemIO::createInput(std::string const& id, bool& input)
{
    mFilterBools[id] = [&input]() -> bool
    {
        return input;
    };

    // Remove input with similar name in input
    auto itr = mFilters.find(id);
    if (itr != mFilters.end())
    {
        mFilters.erase(itr);
    }
}

void SystemIO::createInput(std::string const& id, std::function<bool()> func)
{
    mFilterBools[id] = func;

    // Remove input with similar name in input
    auto itr = mFilters.find(id);
    if (itr != mFilters.end())
    {
        mFilters.erase(itr);
    }
}

void SystemIO::createOutput(std::string const& id, std::function<void(Data const& data)> func)
{
    mOutputs[id] = func;
}

void SystemIO::connect(std::string const& inputId, std::string const& outputId)
{
    mConnections[inputId].push_back(outputId);
}

void SystemIO::disconnect(std::string const& inputId, std::string const& outputId)
{
    auto itr = mConnections.find(inputId);
    if (itr != mConnections.end())
    {
        for (std::size_t i = 0; i < itr->second.size(); i++)
        {
            if (itr->second[i] == outputId)
            {
                itr->second.erase(itr->second.begin() + i);
                return;
            }
        }
    }
}

SystemIO::Data SystemIO::stringToData(std::string const& event)
{
    Data data;
    std::stringstream ss(event);
    std::string t,v;
    while (std::getline(ss,t,'&'))
    {
        std::size_t p = t.find('=');
        if (p != std::string::npos)
        {
            data[t.substr(0,p)] = t.substr(p+1);
        }
    }
    return data;
}

SystemIO::Data SystemIO::eventToData(sf::Event const& event)
{
    Data data;
    data["type"] = sfGetType(event.type);

    // http://www.sfml-dev.org/documentation/2.3/classsf_1_1Event.php#pub-attribs

    if (event.type == sf::Event::Resized)
    {
        data["sizeX"] = std::to_string(event.size.width);
        data["sizeY"] = std::to_string(event.size.height);
    }
    if (event.type == sf::Event::KeyPressed || event.type == sf::Event::KeyReleased)
    {
        data["key"] = keyToString(event.key.code);
        data["alt"] = std::to_string(event.key.alt);
        data["control"] = std::to_string(event.key.control);
        data["shift"] = std::to_string(event.key.shift);
        data["system"] = std::to_string(event.key.system);
    }
    if (event.type == sf::Event::TextEntered)
    {
        std::string s;
        s.push_back(static_cast<char>(event.text.unicode));
        data["unicode"] = s;
    }
    if (event.type == sf::Event::MouseMoved)
    {
        data["cursorX"] = std::to_string(event.mouseMove.x);
        data["cursorY"] = std::to_string(event.mouseMove.y);
    }
    if (event.type == sf::Event::MouseButtonPressed || event.type == sf::Event::MouseButtonReleased)
    {
        data["mouseButton"] = std::to_string(event.mouseButton.button);
        data["cursorX"] = std::to_string(event.mouseButton.x);
        data["cursorY"] = std::to_string(event.mouseButton.y);
    }
    if (event.type == sf::Event::MouseWheelScrolled)
    {
        data["wheel"] = std::to_string(event.mouseWheelScroll.wheel);
        data["dwheel"] = std::to_string(event.mouseWheelScroll.delta);
        data["cursorX"] = std::to_string(event.mouseWheelScroll.x);
        data["cursorY"] = std::to_string(event.mouseWheelScroll.y);
    }
    if (event.type == sf::Event::MouseWheelMoved)
    {
        // Deprecated
        data["dwheel"] = std::to_string(event.mouseWheel.delta);
        data["cursorX"] = std::to_string(event.mouseWheel.x);
        data["cursorY"] = std::to_string(event.mouseWheel.y);
    }
    if (event.type == sf::Event::JoystickMoved)
    {
        data["joystickId"] = std::to_string(event.joystickMove.joystickId);
        data["axis"] = std::to_string(event.joystickMove.axis);
        data["position"] = std::to_string(event.joystickMove.position);
    }
    if (event.type == sf::Event::JoystickButtonPressed || event.type == sf::Event::JoystickButtonReleased)
    {
        data["joystickId"] = std::to_string(event.joystickButton.joystickId);
        data["joystickButton"] = std::to_string(event.joystickButton.button);
    }
    if (event.type == sf::Event::JoystickConnected || event.type == sf::Event::JoystickDisconnected)
    {
        data["joystickId"] = std::to_string(event.joystickConnect.joystickId);
    }
    if (event.type == sf::Event::TouchBegan || event.type == sf::Event::TouchEnded || event.type == sf::Event::TouchMoved)
    {
        data["fingerId"] = std::to_string(event.touch.finger);
        data["cursorX"] = std::to_string(event.touch.x);
        data["cursorY"] = std::to_string(event.touch.y);
    }
    if (event.type == sf::Event::SensorChanged)
    {
        data["sensorType"] = std::to_string(event.sensor.type);
        data["sensorX"] = std::to_string(event.sensor.x);
        data["sensorY"] = std::to_string(event.sensor.y);
        data["sensorZ"] = std::to_string(event.sensor.z);
    }

    return data;
}

std::string SystemIO::sfGetType(sf::Event::EventType type)
{
    // http://www.sfml-dev.org/documentation/2.3/classsf_1_1Event.php#af41fa9ed45c02449030699f671331d4a
    switch (type)
    {
        #define CASE(identifier) case sf::Event::identifier: return "io::"#identifier; break;
        CASE(Closed);
        CASE(Resized);
        CASE(LostFocus);
        CASE(GainedFocus);
        CASE(TextEntered);
        CASE(KeyPressed);
        CASE(KeyReleased);
        CASE(MouseWheelMoved);
        CASE(MouseWheelScrolled);
        CASE(MouseButtonPressed);
        CASE(MouseButtonReleased);
        CASE(MouseMoved);
        CASE(MouseEntered);
        CASE(MouseLeft);
        CASE(JoystickButtonPressed);
        CASE(JoystickButtonReleased);
        CASE(JoystickMoved);
        CASE(JoystickConnected);
        CASE(JoystickDisconnected);
        CASE(TouchBegan);
        CASE(TouchMoved);
        CASE(TouchEnded);
        CASE(SensorChanged);
        default: break;
    }
    return "Unknown";
}

bool SystemIO::passFilter(Data const& filterData, Data const& inputData)
{
    for (auto filter = filterData.begin(); filter != filterData.end(); filter++)
    {
        auto input = inputData.find(filter->first);
        if (input != inputData.end())
        {
            if (filter->second != input->second)
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    return true;
}

void SystemIO::dataToConnected(std::string const& inputId, SystemIO::Data const& data)
{
    // Find connections related to the filter
    auto conn = mConnections.find(inputId);
    if (conn != mConnections.end())
    {
        // For each output
        for (std::size_t j = 0; j < conn->second.size(); j++)
        {
            // Find outputs connected to this filter
            auto out = mOutputs.find(conn->second[j]);
            if (out != mOutputs.end())
            {
                // If valid output
                if (out->second)
                {
                    out->second(data);
                }
            }
        }
    }
}

SystemIO::Data SystemIO::addData(SystemIO::Data inputData, sf::Time dt)
{
    inputData["dt"] = std::to_string(dt.asSeconds());
    return inputData;
}
