----------------------------------------------------------------------------------------------------
Adding the project template to VS:
	- To use a project template in VS copy the zip file to the VS project template directory. It is 
	usualy located in "../Documents/Visual Studio version(i.e. 2013)/Templates/ProjectTemplate/".
	- After copying the zip to the VS project template directory and restarting VS the project 
	template must be available in the 'New Project / Visual C++' popup.
	
----------------------------------------------------------------------------------------------------
Using the VS template project:
	- After creating a project from the 'CGE_Component_ProjectTemplate' template you must follow the
	steps described above to prepare the project:
		1. Raname the file 'CGE_COMPONENT_API.h' with the name of your component;
		2. Rename the namespace 'CGEComponentNamespace' to yours component base namespace;
		3. Rename the definitions 'CGE_COMPONENT_API_EXPORT', 'CGE_COMPONENT_API' and 
		'CGE_COMPONENT_EXP_TEMPLATE' with yours component name;
		4. In the project's properties, C/C++ -> Preprocessor -> Preprocessor definitions, rename the 
		'CGE_COMPONENT_API_EXPORT' definition as you renamed it in the 'CGE_COMPONENT_API.h' file;
		5. Delete the HelloWorld class.