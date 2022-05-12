#ifndef QIIME2EXPORTPLUGIN_H
#define QIIME2EXPORTPLUGIN_H

#include "Plugin.h"
#include "PluginProxy.h"
#include <string>
#include <vector>

class Qiime2ExportPlugin : public Plugin
{
public: 
 std::string toString() {return "Qiime2Export";}
 void input(std::string file);
 void run();
 void output(std::string file);

private: 
 std::string inputfile;
 std::string outputfile;

};

#endif
