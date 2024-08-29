
// COPYRIGHT MOHAMMED YUSSIF
#include <algorithm>
#include <iostream>
#include <memory>
#include <string>
#include <vector>


struct TodoState {
  bool completed;
};

class Todo {
 private:
  std::string id;
  std::string title;
  std::string description;
  TodoState state;

 public:
  Todo(std::string strTitle, std::string strDescription, std::string dId = "1",
       bool dState = false)
      : id{std::move(dId)},
        title{std::move(strTitle)},
        description{std::move(strDescription)},
        state{dState} {}

  const std::string& getTitle() const { return title; }
  const std::string& getDescription() const { return description; }
  const std::string& getId() const { return id; }
  bool isCompleted() const { return state.completed; }
};

class TodoList {
 private:
  std::vector<std::unique_ptr<Todo>> todos;

 public:
  void createTodo(const std::string& title, const std::string& description) {
    todos.push_back(std::make_unique<Todo>(title, description));
  }

  void displayTodos() const {
    if (todos.empty()) {
      std::cout << "No todos in the list.\n";
      return;
    }
    for (const auto& todo : todos) {
      std::cout << "ID: " << todo->getId() << ", Title: " << todo->getTitle()
                << ", Description: " << todo->getDescription()
                << ", Completed: " << (todo->isCompleted() ? "Yes" : "No")
                << std::endl;
    }
  }

  void deleteTodo(const std::string& id) {
    auto it = std::find_if(todos.begin(), todos.end(),
                           [&id](const std::unique_ptr<Todo>& todo) {
                             return todo->getId() == id;
                           });
    if (it != todos.end()) {
      todos.erase(it);
      std::cout << "Todo with ID " << id << " deleted.\n";
    } else {
      std::cout << "Todo with ID " << id << " not found.\n";
    }
  }
};

int main() {
  TodoList todoList;
  std::string choice, title, description, id;

  while (true) {
    std::cout << "\n1. Add Todo\n2. Display Todos\n3. Delete Todo\n4. "
                 "Exit\nEnter your choice: ";
    std::getline(std::cin, choice);

    if (choice == "1") {
      std::cout << "Enter title: ";
      std::getline(std::cin, title);
      std::cout << "Enter description: ";
      std::getline(std::cin, description);
      todoList.createTodo(title, description);
    } else if (choice == "2") {
      todoList.displayTodos();
    } else if (choice == "3") {
      std::cout << "Enter ID of todo to delete: ";
      std::getline(std::cin, id);
      todoList.deleteTodo(id);
    } else if (choice == "4") {
      break;
    } else {
      std::cout << "Invalid choice. Please try again.\n";
    }
  }

  return 0;
}