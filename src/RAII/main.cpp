#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>

class FileHandler
{
public:
    explicit FileHandler(const std::string &filename)
        : file(filename)
    {
        if (!file.is_open())
        {
            throw std::runtime_error("Failed to open file: " + filename);
        }
    }
    // The destructor ensures that the file is properly closed when the FileHandler object
    // goes out of scope, preventing resource leaks.
    ~FileHandler()
    {
        if (file.is_open())
        {
            file.close();
        }
    }

    // Disables copying to prevent multiple instances managing the same resource.
    FileHandler(const FileHandler &) = delete;
    FileHandler &operator=(const FileHandler &) = delete;
    FileHandler(FileHandler &&) = default;
    FileHandler &operator=(FileHandler &&) = default;

    std::ofstream &get() { return file; }

private:
    std::ofstream file;
};

int main()
{
    try
    {
        FileHandler file("example.txt");
        file.get() << "Hello RAII\n";
        // The file will be closed automatically when exiting the scope.
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        return 1;
    }
}
