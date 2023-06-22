#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

class State {
private:
    string name;

public:
    State(const string& name) : name(name) {}

    string getStateName() const {
        return name;
    }

    bool operator==(const State& other) const {
        return name == other.name;
    }
};

namespace std {
    template<>
    struct hash<State> {
        size_t operator()(const State& state) const {
            return hash<string>()(state.getStateName());
        }
    };
}

class Automaton {
private:
    unordered_map<State, unordered_map<char, State>> transitions;
    State startState;
    State* acceptStates;
    int acceptStatesCount;

public:
    Automaton(const unordered_map<State, unordered_map<char, State>>& transitions,
              const State& startState, State* acceptStates, int acceptStatesCount)
        : transitions(transitions), startState(startState), acceptStates(acceptStates), acceptStatesCount(acceptStatesCount) {}

    bool isAcceptedString(const string& str) {
        State currentState = startState;

        for (char c : str) {
            const auto& currentTransitions = transitions[currentState];
            auto it = currentTransitions.find(c);
            if (it == currentTransitions.end()) {
                return false;
            }
            currentState = it->second;
        }

        for (int i = 0; i < acceptStatesCount; ++i) {
            if (currentState == acceptStates[i]) {
                return true;
            }
        }

        return false;
    }

    void printTransitionTable() {
        cout << "Transition Table:" << endl;
        cout << "-----------------" << endl;
        cout << "State\t| 0\t| 1\t|" << endl;
        cout << "-----------------" << endl;

        for (const auto& stateTransitions : transitions) {
            const State& state = stateTransitions.first;
            const unordered_map<char, State>& stateMap = stateTransitions.second;

            cout << state.getStateName() << "\t| ";

            auto zeroTransition = stateMap.find('0');
            if (zeroTransition != stateMap.end()) {
                cout << zeroTransition->second.getStateName() << "\t| ";
            } else {
                cout << "-\t| ";
            }

            auto oneTransition = stateMap.find('1');
            if (oneTransition != stateMap.end()) {
                cout << oneTransition->second.getStateName() << "\t| ";
            } else {
                cout << "-\t| ";
            }

            cout << endl;
        }

        cout << "-----------------" << endl;
    }
};

int main() {
unordered_map<State, unordered_map<char, State>> transitions{
    { State("q0"), { {'0', State("q1")} } },
    { State("q1"), { {'1', State("q2")} } },
    { State("q2"), { {'1', State("q3")}, {'0', State("q1")} } },
    { State("q3"), { {'1', State("q2")} } }
};

    State startState("q0");
    State finalStates[] = { State("q3") };
    int count = 1;

    Automaton automaton(transitions, startState, finalStates, count);

    string string1 = "010000101";
    string string2 = "0110000010";
    string string3 = "000001110";
    string string4 = "111111";

    automaton.printTransitionTable();
    string input = "";
    cout<<"Enter your input"<<endl;
    cin>>input;

    
    
    if(automaton.isAcceptedString(input)){
        cout<<"The string is accepted"<<endl;
    }
    else{
        cout<<"The string is rejected"<<endl;
    }

    // cout << string1 << " is accepted: " << automaton.isAcceptedString(string1) << endl;
    // cout << string2 << " is accepted: " << automaton.isAcceptedString(string2) << endl;
    // cout << string3 << " is accepted: " << automaton.isAcceptedString(string3) << endl;
    // cout << string4 << " is accepted: " << automaton.isAcceptedString(string4) << endl;

    return 0;
}

