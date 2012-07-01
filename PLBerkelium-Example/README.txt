This example utilizes the PLBerkelium plugin, https://github.com/PixelLightCommunity/Plugins/tree/master/PLBerkelium

You can also use this example with the PLAwesomium plugin (https://github.com/PixelLightCommunity/Plugins/tree/master/PLAwesomium),
this because PLBerkelium and PLAwesomium practically are identical in their methods.

The examples are using relative paths. Clone the examples Git repository into the same directory you cloned the plugins Git repository into:
- <my directory name>
	- Examples
		- Bin
		- PLBerkelium-Example
		- ...
	- Plugins
		- Bin
		- PLBerkelium
		- ...

# Building under Windows using Visual Studio 2010 and the current Git version of PixelLight
1. Add an environment variable "PL_ROOT" pointing to the location of your PixelLight Git repository (e.g. "C:\pixellight\")
2. Add an environment variable "BERKELIUM_ROOT" pointing to the location of your Berkelium copy (e.g. "C:\berkelium\")
3. Restart Visual Studio in case it's currently opened
4. Open "PLBerkelium-Example.sln" and build it
