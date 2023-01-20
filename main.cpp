#include <iostream>
#include <filesystem>
#include <vector>

int main() {

    auto recursiveGetFileNamesByExtension =
            [](std::filesystem::path path,
               const std::string extension){

                std::vector <std::string> fileNames;

                for(auto& p: std::filesystem::recursive_directory_iterator(path)){

                    if(p.is_regular_file()){
                      auto n =  p.path().extension().compare(extension);
                      if (n == 0){
                        fileNames.push_back(p.path().filename().string());
                      }
                    }
                };
                return fileNames;
                };

    auto files = recursiveGetFileNamesByExtension("E:\\SkillboxProject\\practice-14",".cpp");
    for (auto f:files){
        std::cout << f << std::endl;
    }
}
