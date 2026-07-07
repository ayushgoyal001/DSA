class Node {
public:
    string url;
    Node* back;
    Node* forward;

    Node(string homepage) {
        url = homepage;
        back = NULL;
        forward = NULL;
    }
};

class BrowserHistory {
public:
    Node* current;

    BrowserHistory(string homepage) {
        current = new Node(homepage);
    }

    void visit(string url) {
        Node* visit = new Node(url);
        current->forward = visit;
        visit->back = current;
        current = visit;
    }

    string back(int steps) {
        while (steps > 0 && current->back != NULL) {
            current = current->back;
            steps--;
        }
        return current->url;
    }

    string forward(int steps) {
        while (steps > 0 && current->forward != NULL) {
            current = current->forward;
            steps--;
        }
        return current->url;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */