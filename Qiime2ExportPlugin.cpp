#include "PluginManager.h"
#include <stdio.h>
#include <stdlib.h>
#include "Qiime2ExportPlugin.h"

void Qiime2ExportPlugin::input(std::string file) {
 inputfile = file;
}

void Qiime2ExportPlugin::run() {
   
}

void Qiime2ExportPlugin::output(std::string file) { 
   std::string command = "export OLDPATH=${PATH}; ";
   command += "export PATH=${CONDA_HOME}/bin/:${PATH}; ";
   command += "eval \"$(conda shell.bash hook)\"; ";
   command += "conda activate qiime2-2021.4; ";
   command += "qiime tools export --input-path "+inputfile+" --output-path "+file+"; ";
   //command += "qiime tools import --type \'SampleData[PairedEndSequencesWithQuality]\' --input-path "+inputfile+" --output-path "+file+" --input-format PairedEndFastqManifestPhred33; ";

//qiime tools import \
  --type 'SampleData[PairedEndSequencesWithQuality]' \
  --input-path AlphaFinal1.manifest \
  --output-path AlphaFinal1-paired-end-demux.qza \
  --input-format PairedEndFastqManifestPhred33V2
 //std::cout << command << std::endl;
   command += "conda deactivate; ";
   command += "conda deactivate; ";
   command += "export PATH=${OLDPATH}";
 std::cout << command << std::endl;


 system(command.c_str());
}

PluginProxy<Qiime2ExportPlugin> Qiime2ExportPluginProxy = PluginProxy<Qiime2ExportPlugin>("Qiime2Export", PluginManager::getInstance());
