# sensaur-arduino

The repository contains Arduino/ESP32 code for the Sensaur project. These sketches/libraries are used for the hub board 
and sensaur/actuator devices that plug into the hub board.

The hub board has two forms: one that attaches to a Raspberry Pi and one that attaches to an ESP32 microcontroller.
See the [sensaur repo](https://github.com/manylabs/sensaur) for python code that runs on the Rasbperry Pi.

The device boards connect to the hub using audio cables that carry power and serial data. The communication between the hub and the devices 
uses a single serial line for both transmitting and receiving (i.e. half-duplex serial).

## Owner/hub/device/component IDs

The owner ID corresponds to the person or organization who owns or manages a device. It is assigned by the server.

The hub ID is assigned using the hub configuration utility. (For ESP32 hubs, we expect to do configuration over BLE.)

The device ID is a 32-bit integer (displayed in hexidecimal) that is self-assigned by each device (sensor/actuator board). 
The device ID is stored on the device and preserved when it is moved from one hub to another. Device IDs are randomly generated, 
so they may not be globally unique, though it should be reasonable to assume they are unique within a single owner.

Each device can have multiple components (e.g. temperature and humidity). Components are identified by the device ID, followed by a dash, followed by the 
first five letters of component type. (It is up to the device designer to make sure the first five letters of the component types are not repeated on 
a single device.)

## MQTT topics

The hub can send values to an MQTT server. We use the following topics:

*   `[owner_id]/hub/[hub_id]/status` (JSON dictionary with wifi, firmware, etc. info from hub)
*   `[owner_id]/hub/[hub_id]/config` (JSON dictionary with polling rate, firmware updates, etc.)
*   `[owner_id]/hub/[hub_id]/devices` (JSON dictionary of device info by device_id)
*   `[owner_id]/hub/[hub_id]/sensors` (JSON dictionary with sensor values (from hub) by component_id)
*   `[owner_id]/hub/[hub_id]/actuators` (JSON dictionary with actuator values (for hub) by component_id)
*   `[owner_id]/device/[device_id]` (string value of current hub_id for this device)

## Running the hub simulator

The simulator is in the `sensaur-hub-sim` folder. 

1.  Create a sub-folder called `cert` containing the key and certificates for this hub.
2.  Copy `sample_config.hjson` to `config.hjson` and edit the host, certificate paths, etc. as needed.
3.  Run `sim.py`
