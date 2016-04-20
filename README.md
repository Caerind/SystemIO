# SystemIO

=======================================================================================================
I wanted to handle the same way few Inputs :

- Event (like sf::Event)
- User event (like AI or Player actions or Packet via network or ...)
- Realtime event (like toggle or sf::Keyboard::isKeyPressed or ...)

And I wanted to connect them to smart Outputs, which will be able to have Data from the Input


=======================================================================================================
Here the basic example, you can have it from the main.cpp :

`    #include <SFML/Graphics.hpp>
    #include "SystemIO.hpp"
    
    int main()
    {
        SystemIO system;
    
        /// Simple example
    
        // Create your input
        system.createInput("i1", "type=io::MouseButtonPressed&mouseButton=1");
	    system.createInput("i2", "type=io::KeyPressed&key=A");
	    system.createInput("i3", "type=IA-Event");
	    system.createInput("i4", "type=Packet&id=PlayerConnected");
    
	    // Create your output
        system.createOutput("o", [](SystemIO::Data const& data)
        {
            for (auto itr = data.begin(); itr != data.end(); itr++)
            {
                std::cout << itr->first << " : " << itr->second << std::endl;
            }
        });
    
        // Connect inputs to output
        system.connect("i1","o");
        system.connect("i2","o");
        system.connect("i3","o");
        system.connect("i4","o");
    
        // Emit your own event
        system.handleEvent("type=IA-Event&id=0x00001");
    
        // Member variable
        bool toggle = false;
    
        // Event that emit another event (and change variable)
    	system.createInput("t1", "type=io::KeyPressed&key=P");
	    system.createOutput("o1", [&system,&toggle](SystemIO::Data const& data)
	    { 
	    	system.handleEvent("type=Packet&id=PlayerConnected");
	    	toggle = !toggle; 
	    });
        system.connect("t1","o1");
    
	    // Reference access to boolean for Realtime events
	    system.createInput("t2", toggle);
	    system.createOutput("o2", [](SystemIO::Data const& data) { std::cout << "ON" << std::endl; });
	    system.connect("t2","o2");
    
	    // Reference access to function returning boolean for Realtime events
	    system.createInput("t3", []() -> bool
	    { 
	    	return sf::Keyboard::isKeyPressed(sf::Keyboard::Z);
	    });
	    system.createOutput("o3", [](SystemIO::Data const& data)
    	{
	    	std::cout << "Move" << std::endl; 
	    });
	    system.connect("t3","o3");
    
    
    
    	/// Complex example : key binding

    	// Member variable
    	sf::Keyboard::Key keyUp = sf::Keyboard::Up;

	    // Handle key that make moving
        system.createInput("keyUp", [&keyUp]() -> bool
    	{ 
	    	return sf::Keyboard::isKeyPressed(keyUp); 
	    });
        system.createOutput("moveUp", [](SystemIO::Data const& data) 
	    { 
	    	std::cout << "MoveUp" << std::endl; 
	    });
        system.connect("keyUp","moveUp");
    
        // Handle key + alt, to change the key
        system.createInput("keyAlt", "type=io::KeyPressed&alt=1");
        system.createOutput("keyChange", [&keyUp](SystemIO::Data const& data)
        {
            if (SystemIO::has(data,"key"))
            {
                std::cout << "key : " + data.at("key") << std::endl;
                sf::Keyboard::Key k = SystemIO::stringToKey(data.at("key"));
                if (k != sf::Keyboard::Key::LAlt)
                {
                    keyUp = k;
                }
            }
        });
        system.connect("keyAlt","keyChange");
    
        // Main Loop
    
        sf::RenderWindow window(sf::VideoMode(400, 400), "IO");
        sf::Clock clock;
        while (window.isOpen())
        {
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
    
                // Directly handle event here
                system.handleEvent(event); //  If you don't want this, you can use system.setWindow(&win); once and events will be handled
            }
    
            // Update each frame
            system.update(clock.restart());
    
            window.clear();
            window.display();
        }
    
        return 0;
    }
    `

=======================================================================================================
Here, I include the documentation about creating / reading Data :

( **keyId** : (varType) Short Desc - Which Inputs can produce it)

- **dt** : (float) Delta seconds - All
- **type** : (string) Get the type of input - Events & Realtime
- **realtimeId** : (string) Id of the realtime that produced the input - Realtime
- **sizeX** : (int) New window size x - Event Resized
- **sizeY** : (int) New window size y - Event Resized
- **key** : (string) The key - Event KeyPressed, KeyReleased
- **alt** : (bool) If the alt key is pressed too - Event KeyPressed, KeyReleased
- **control** : (bool) If the control key is pressed too - Event KeyPressed, KeyReleased
- **shift** : (bool) If the shift key is pressed too - Event KeyPressed, KeyReleased
- **system** : (bool) If the system key is pressed too - Event KeyPressed, KeyReleased
- **unicode** : (string) The character entered - Event TextEntered
- **cursorX** : (int) The position of the cursor x - Event MouseMoved, MouseButtonPressed), MouseButtonReleased, MouseWheelScrolled, MouseWheelMoved, TouchBegan, TouchEnded, TouchMoved
- **cursorY** : (int) The position of the cursor y - Event MouseMoved, MouseButtonPressed), MouseButtonReleased, MouseWheelScrolled, MouseWheelMoved, TouchBegan, TouchEnded, TouchMoved
- **mouseButton** : (int) The mouse button - Event MouseButtonPressed, MouseButtonReleased
- **wheel** : (int) The wheel used - Event MouseWheelScrolled
- **dwheel** : (float/int) The delta ticks of the wheel - Event MouseWheelScrolled, MouseWheelMoved (this last event is deprecated by SFML)
- **joystickId** : (int) Joystick Id - Event JoystickMoved, JoystickButtonPressed, JoystickButtonReleased, JoystickConnected, JoystickDisconnected
- **axis** : (int) Axis on which the joystick moved - Event JoystickMoved
- **position** : (float) New position in range (-100,100) - Event JoystickMoved
- **joystickButton** : (int) Button Id - Event JoystickButtonPressed, JoystickButtonReleased
- **fingerId** : (int) Finger Id - Event TouchBegan, TouchEnded, TouchMoved
- **sensorType** : (int) Sensor Type - Event SensorChanged
- **sensorX** : (float) Value of sensor x - Event SensorChanged
- **sensorY** : (float) Value of sensor y - Event SensorChanged
- **sensorZ** : (float) Value of sensor z - Event SensorChanged



- All the data here come from sfml events : http://www.sfml-dev.org/documentation/2.3/classsf_1_1Event.php#pub-attribs

- If you want to see the types of events (add *io::*) : http://www.sfml-dev.org/documentation/2.3/classsf_1_1Event.php#af41fa9ed45c02449030699f671331d4a
    
	
	
=======================================================================================================
TODO :

- Operator AND


=======================================================================================================
For anything, contact me at : charles.mailly@free.fr
