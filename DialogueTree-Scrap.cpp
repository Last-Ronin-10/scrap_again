#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <memory>
class DialogueNode;
struct DialogueOption{
    std::string text;
    std::shared_ptr<DialogueNode> nextNode;
    DialogueOption(const std::string& t, std::shared_ptr<DialogueNode> n) : text(t), nextNode(n) {}
};
class DialogueNode{
    public:
    std::string text;
    std::vector<DilogueOptions> options;
    DialogueNode(const std::string& t) : text(t) {};
    void addoption(const std::string& optiontex, std::shared_ptr<DialogueNode> nextNode) {
        options.emplace_back(optiontex, nextNode);
    }
};
class Implementation{
    std::unordered_map<std::string, std::shared_ptr<DialogueNode>> nodes;
    public:
    Implementation(std::unordered_map<std::string, std::shared_ptr<DialogueNode>> n) : nodes(n) {}
    void startdialogue(){
        while(true) {
            std::string currentNodeKey = "start"; 
            while (nodes.find(currentNodeKey) != nodes.end()) {
                auto currentNode = nodes[currentNodeKey];
                std::cout << currentNode->text << std::endl;
                if (currentNode->options.empty()) {
                    break; 
                }
                for (size_t i = 0; i < currentNode->options.size(); ++i) {
                    std::cout << i + 1 << ": " << currentNode->options[i].text << std::endl;
                }
                int choice;
                std::cin >> choice;
                if (choice < 1 || choice > static_cast<int>(currentNode->options.size())) {
                    std::cout << "Invalid choice, try again." << std::endl;
                    continue; 
                currentNodeKey = currentNode->options[choice - 1].nextNode->text;             }
            break; 
    }
}