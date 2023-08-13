#include <string>
#include <cmath>
#include <vector>
#include <stack>
#include <map>
#include <stdexcept>
#include <algorithm>
#include <iostream> /* Remove after testing of string constructors */

//TODO create options to convert a string into a class data
namespace math{
    //TODO finish it
    class InfinitePrecisionNumber{
        private : 
            std::string num;
            bool isNegative = false;
        public:
            InfinitePrecisionNumber(const double& d) noexcept{
                this->num = std::to_string(d);
            }

            friend std::ostream& operator<<(std::ostream& os, const InfinitePrecisionNumber& ipn) noexcept{
                if(ipn.isNegative) os << "-";
                os << ipn.num;
                return os;
            }

            InfinitePrecisionNumber operator+(const InfinitePrecisionNumber& other) const noexcept{
            
            }

            InfinitePrecisionNumber operator-(const InfinitePrecisionNumber& other) const noexcept{
            
            }

            InfinitePrecisionNumber operator*(const InfinitePrecisionNumber& other) const noexcept{
            
            }

            InfinitePrecisionNumber operator/(const InfinitePrecisionNumber& other) const noexcept{
            
            }
    };

    constexpr static const double tolerance = 1e-6;
    class StandardForm {
        private:
            double num = 1;
            int power = 1;

            bool isInValidRange() const noexcept{
               return (num >= 1 && num <= 10) || (num >= -10 && num <= -1);
            }

        public:
            StandardForm(){}

            StandardForm(const double& n) noexcept{
                this->setNum(n);
            }

            StandardForm(const double& n,const int& pow) noexcept{
                if(isInValidRange()){
                    setPower(pow);
                    setNum(n);
                }
                else{
                    setNum(n);
                    setPower(pow);
                }
            }

            StandardForm(const std::string& s){
                try {
                    //valid number so no string manipulation
                    setNum(std::stod(s));
                }
                catch(const std::out_of_range& exception){
                    size_t pos = s.find('e');
                    //String is doesnt contain an e in it so eg : 2*10^3 or some invalid number
                    if(pos == std::string::npos){
                        pos = s.find('^');
                        if(pos == std::string::npos) throw std::invalid_argument("Invalid Number given :" + s);
                        num = stod(s.substr(0,pos - 2));
                        power = stoi(s.substr(pos +1,s.length() - 1));
                    }
                    //string contains an e in it so eg : its 2e10
                    else{
                        num = stod(s.substr(0, pos));
                        power = stoi(s.substr(pos + 1));
                    }
                }
            }

            void setNum(const double& n) noexcept {
                this->num = n;

                if (isInValidRange()) return;

                double absNumber = std::abs(n);
                int logZehn = std::ceil(std::log10(absNumber));
                this->num /= std::pow(10, logZehn);
                this->power = logZehn;

                if (this->num < 0) this->num = -this->num;

                if(this->num > 0 && this->num < 1) {
                    this->num *= 10;
                    this->power -= 1;
                }

            }

            double getNum() const noexcept{
                return num;
            }

            void setPower(const int& n) noexcept {
                power = n;
            }

            int getPower() const noexcept{
                return power;
            }

            inline void toNegative() noexcept{
                this->num = -this->num;
            }

            inline std::string toScientificNotation() const noexcept{
                return std::to_string(num) + "e" + std::to_string(power);
            }

            inline std::string toEngineeringNotation() const noexcept {
                return std::to_string(num) + "*10^" + std::to_string(power);
            }

            inline double toDouble() const noexcept{
                return std::stod(this->toScientificNotation());
            }

            //TODO doesnt work correctly
            inline std::string toAppropriateFormat() const noexcept{
                return this->toScientificNotation();
            }

            friend std::ostream& operator<<(std::ostream& os, const StandardForm& sf) noexcept{
                os << sf.toAppropriateFormat();
                return os;
            }

            StandardForm operator+(const StandardForm& other) const noexcept{
                int max_power = std::max(power, other.power);
                return StandardForm(num * std::pow(10, power - max_power) + other.num * std::pow(10, other.power - max_power), max_power);
            }

            StandardForm operator+(const double& other) const noexcept{
                return (*this +  StandardForm(other));
            }

            void operator+=(const StandardForm& other) noexcept{
                *this = *this + other;
            }

            void operator+=(const double& other) noexcept{
                *this = *this +  StandardForm(other);
            }

            StandardForm operator-(const StandardForm& other) const noexcept{
                int min = std::min(power,other.power);
                return  StandardForm(num * std::pow(10,power - min) - other.num * std::pow(10,other.power - min),min);
            }
            StandardForm operator-(const double& other) const{
                return (*this -  StandardForm(other));
            }
            StandardForm operator-() const noexcept{
                return StandardForm(-this->num,this->power);
            }
            void operator-=(const StandardForm& other) noexcept{
                *this = *this - other;
            }

            void operator-=(const double& other) noexcept{
                *this = *this - StandardForm(other);
            }

            StandardForm operator*(const StandardForm& other) const noexcept{
                return  StandardForm(num * other.num,power + other.power);
            }
            StandardForm operator*(const double& other) const noexcept{
                return *this *  StandardForm(other);
            }
            void operator*=(const StandardForm& other) noexcept{
                *this = *this * other;
            }
            void operator*=(const double& other) noexcept{
                *this = *this * StandardForm(other);
            }


            StandardForm operator/(const StandardForm& other) const noexcept{
                return  StandardForm(num / other.num,power - other.power);
            }
            StandardForm operator/(const double& other) const noexcept{
                return *this /  StandardForm(other);
            }
            void operator/=(const StandardForm& other) noexcept{
                *this = *this / other;
            }
            void operator/=(const double& other) noexcept{
                *this = *this / StandardForm(other);
            }

            StandardForm operator^(const StandardForm& other) const noexcept{
               return StandardForm(std::pow(num, other.num), power * other.power);
            }
            StandardForm operator^(const double& other) const noexcept{
                return *this ^  StandardForm(other);
            }
            void operator^=(const StandardForm& other) noexcept{
                *this = *this ^ other;
            }

            void operator^=(const double& other) noexcept{
                *this = *this ^ StandardForm(other);
            }

            bool operator==(const StandardForm& other) const noexcept{
                return (num == other.num) && (power == other.power);
            }
            bool operator==(const double& other) const noexcept{
                return *this ==  StandardForm(other);
            }

            bool operator!=(const StandardForm& other) const noexcept{
                return !(*this == other);
            }
            bool operator!=(const double& other) const{
                return *this != StandardForm(other);
            }

            bool operator>(const StandardForm& other) const noexcept{
                return (power != other.power) ? power > other.power : num > other.num;
            }
            bool operator>(const double& other) const noexcept{
                return *this > StandardForm(other);
            }

            bool operator<(const StandardForm& other) const noexcept{
                return (power != other.power) ? power < other.power : num < other.num;
            }
            bool operator<(const double& other) const noexcept{
                return *this < StandardForm(other);
            }

            bool operator<=(const StandardForm& other) const noexcept{
                return (power != other.power) ? num <= other.num : power <= other.power;
            }
            bool operator<=(const double& other) const noexcept{
                return *this <= StandardForm(other);
            }

            bool operator>=(const StandardForm& other) const noexcept{
                return (power != other.power) ? num >= other.num : power >= other.power;
            }
            bool operator>=(const double& other) const noexcept{
                return *this >=  StandardForm(other);
            }

            void roundToSf(const int& sf) noexcept{
                double factor =std::pow(10, sf - 1 - power);
                num = std::round(num * factor);
                num /= factor;
            }
            void roundToDp(const int& dp) noexcept{
                int x = std::pow(10,dp);
                num = std::round(num * x) / x;
            }

            StandardForm min(const StandardForm& other) const noexcept{
                if(*this < other) return *this;
                return other;
            }
            StandardForm min(const double& other) const noexcept{
                if(*this < other) return *this;
                return other;
            }

            StandardForm max(const StandardForm& other) const noexcept{
                if(*this > other) return *this;
                return other;
            }
            StandardForm max(const double& other) const noexcept{
                if(*this > other) return *this;
                return other;
            }

            StandardForm sqrt() const noexcept{
                return *this ^ 0.5;
            }
            StandardForm cbrt() const noexcept{
                return *this ^ (1/3);

            }
            StandardForm root(const double& root) const noexcept{
                return *this ^ (1 / root);
            }

            StandardForm abs() const noexcept{
                return math::StandardForm(num,std::abs(power));
            }

            StandardForm log(const StandardForm& other) const noexcept{
                return StandardForm(std::log(num) / std::log(other.num),power - other.power);

            }
            StandardForm log(const double& other) const noexcept{
                return log( StandardForm(other));
            }
            StandardForm log10() const noexcept{
                return log(10);
            }

            StandardForm sin() const noexcept{
                StandardForm result = *this;
                StandardForm term = *this;
                int n = 3;
                bool positive = false;
                while (term.abs() > tolerance) {
                    result = result + term;
                    positive = !positive;
                    term.toNegative();
                    term = term ^ 2 / (n * (n - 1));
                    n += 2;
                }
                return result;
            }
            StandardForm cos() const noexcept{
                StandardForm sinSquared =  ((*this) / 2.0) ^ 2;
                return StandardForm(1.0 - 2.0 * sinSquared.num, sinSquared.power);
            }
            StandardForm tan() const noexcept{
                return this->sin() / this->cos();
            }
    };

    //TODO remove NO_OPERATOR as its useless cuz then its just invisible add
    enum class Operation{
        NO_OPERATOR = 0,
        ADD = 1,
        SUBTRACT = 2,
        MULTIPLY = 3,
        DIVIDE = 4,
        POWER = 5,
    };

    static int getOperationValue(const Operation& operation){
        return static_cast<int>(operation);
    }

    static std::string getOperationAsString(const Operation& operation){
        switch(operation){
            case Operation::NO_OPERATOR : return "";
            case Operation::ADD : return "+";
            case Operation::SUBTRACT : return "-";
            case Operation::MULTIPLY : return "*";
            case Operation::DIVIDE : return "/";
            case Operation::POWER : return "^";
        }
    }

    std::ostream& operator<<(std::ostream& os, const Operation& operation) noexcept {
        os << getOperationAsString(operation);
        return os;
    }

    static bool isAdditionSubtractionOrNoOperation(const Operation& operation){
        return operation == Operation::ADD || operation == Operation::SUBTRACT || operation == Operation::NO_OPERATOR;
    }

    static const StandardForm variableInMapNichtDa = StandardForm(0,0);
    class Variables{
        private : std::map<char,StandardForm> variables;
        public:
            using mapType =  std::map<char,StandardForm>;

            Variables(const mapType& vars) noexcept{
                this->variables = vars;
            }

            //TODO doenst work correctly
            Variables(const std::string& expressionot){
                if(expression.empty()) return;

                std::cout << "Variables object string constructor\n";
                
                std::map<char, StandardForm> result;

                for(std::string::const_iterator it = expression.begin(); it != expression.end(); ++it){
                    if(!std::isalpha(*it)) throw std::invalid_argument("This isnt a valid variable expression :" + expression + " but hauptsachlichteil :" +  expression.substr(std::distance(expression.begin(),it)));
                    
                    std::cout << "it is a letter : " << *it << std::endl;

                    if(it + 1 == expression.end()){
                        result[*it] = result.find(*it) == result.end() ? StandardForm() : result[*it] ^ 2;
                        std::cout << "last variable : " << *it << std::endl;
                        std::cout << "-------------\n";
                        continue;
                    }

                    if(std::isalpha(*(it + 1)) ){ 
                        result[*it] = result.find(*it) == result.end() ? StandardForm() : result[*it] ^ 2;
                        std::cout << "it + 1 is a letter : " << *(it + 1) << std::endl;
                        std::cout << "-------------\n";
                        continue;
                    }
                    
                    if(*(it + 1) != '^') throw std::invalid_argument("This isnt a valid variable expression :" + expression + " but hauptsachlichteil :" +  expression.substr(std::distance(expression.begin(),it)) + "as it doesnt contain a ^ in it");
                    std::cout << "it + 1 is ^\n";

                    if(*(it + 2) == '0') continue;
                    if(*(it + 2) == '1' &&  !isdigit(*(it + 2))){ 
                        result[*it] = result.find(*it) == result.end() ? StandardForm() : result[*it] ^ 2;
                        std::cout << "it + 2 is 1 : " << *(it + 2) << std::endl;
                        std::cout << "-------------\n";
                        it = it + 2;
                        continue;
                    }
                    if(*(it + 2) == '('){ 
                        std::cout << "it + 2 is ( : " << *(it + 2) << std::endl;    
                        auto currentPosition = std::distance(expression.begin(),it + 2) + 1;
                        size_t endPos = expression.find(')', currentPosition);
                        if (endPos == std::string::npos) throw std::invalid_argument("This isn't a valid variable expression: " + expression);
                        std::string s = expression.substr(currentPosition, endPos - currentPosition - 1);
                        std::cout << "Given Substring : " << s << std::endl;
                        StandardForm sf(s);
                        result[*it] = result.find(*it) == result.end() ? sf : result[*it] * sf;
                        it = expression.begin() + endPos;
                        std::cout << "-------------\n";
                        continue;
                    }
                    else{
                        std::string::const_iterator newIterator = it + 2;
                        while(isdigit(*newIterator)){
                            newIterator++;
                        }
                        std::string s = expression.substr(std::distance(expression.begin(), it) + 2, newIterator - (it + 2));
                        std::cout << "Given Substring : " << s << std::endl;
                        StandardForm sf(s);
                        result[*it] = result.find(*it) == result.end() ? sf : result[*it] * sf;
                        it = newIterator - 1;
                        std::cout << "-------------\n";
                        continue;
                    }   
                    throw std::invalid_argument("This isnt a valid variable expression :" + expression);
                }
                std::cout << "Variables object string constructor finished\n";

                this->variables = result;
            }

            mapType getAll() const noexcept{
                return this->variables;
            }

            std::string asString() const noexcept{
                std::string s = "";
                for(const math::Variables::mapType::const_iterator::value_type& pair : this->variables){
                    s += pair.first;
                    if(pair.second > 1.0) s += "^" + pair.second.toAppropriateFormat();
                }
                return s;
            }

            bool containsVariables() const noexcept{
                return !this->variables.empty();
            }

            friend std::ostream& operator<<(std::ostream& os, const Variables& term){
                os << term.asString();
                return os;
            }

            Variables operator*(const Variables& other) const noexcept{
                mapType alegbra = other.variables;
                for(const mapType::const_iterator::value_type& pair:this->variables){
                    alegbra[pair.first] = alegbra[pair.first] + pair.second;
                }
                return Variables(alegbra);
            }

            Variables operator/(const Variables& other) const noexcept{
                mapType alegbra = other.variables;
                for(const mapType::const_iterator::value_type& pair:this->variables){
                    alegbra[pair.first] = alegbra[pair.first] - pair.second;
                }
                return Variables(alegbra);
            }

            StandardForm operator[](const char& ch) const noexcept{
                auto it = this->variables.find(ch);
                return it != this->variables.end() ? it->second : variableInMapNichtDa;
            }
            Variables& operator=(const Variables& other) noexcept{
                if (this != &other) variables = other.variables;
                return *this;
            }
            bool operator==(const Variables& other) const noexcept{
                return this->variables == other.variables;
            }
            bool operator!=(const Variables& other) const noexcept{
                return !(*this == other);
            }
            //TODO remove this as soon as possible
            bool [[deprecated("Just for testing")]]operator<(const Variables& other) const {
                if(*this == other) return false;
                return true;
            }
        };

    class AlgebraicTerm{
        private:
            StandardForm number = StandardForm();
            Variables variables = Variables("");
            Operation operation = Operation::NO_OPERATOR;

            std::vector<AlgebraicTerm> add(const AlgebraicTerm& other) const noexcept{
                std::vector<AlgebraicTerm> result;
                if(this->variables == other.variables){
                    result.reserve(1);
                    result.push_back(AlgebraicTerm(this->number + other.number,this->variables,this->operation));
                }
                else{
                    result.reserve(2);
                    result.push_back(*this);
                    result.push_back(other);
                }
                return result;
            }

            std::vector<AlgebraicTerm> minus(const AlgebraicTerm& other) const noexcept{
                std::vector<AlgebraicTerm> result;
                if(this->variables == other.variables){
                    result.reserve(1);
                    result.push_back(AlgebraicTerm(this->number - other.number,this->variables,this->operation));
                }
                else{
                    result.reserve(2);
                    result.push_back(*this);
                    result.push_back(other);
                }
                return result;
            }

            std::vector<AlgebraicTerm> multiply(const AlgebraicTerm& other) const noexcept{
                std::vector<AlgebraicTerm> result;
                result.reserve(1);
                result.push_back(AlgebraicTerm(this->number * other.number,this->variables * other.variables,this->operation));
                return result;
            }

            std::vector<AlgebraicTerm> divide(const AlgebraicTerm& other) const noexcept{
                std::vector<AlgebraicTerm> result;
                result.reserve(1);
                result.push_back(AlgebraicTerm(this->number / other.number,this->variables / other.variables,this->operation));
                return result;
            }

            std::vector<AlgebraicTerm> power(const AlgebraicTerm& other) const noexcept{
                std::vector<AlgebraicTerm> result;
                if(!this->variables.containsVariables() && !other.variables.containsVariables()){
                    result.reserve(1);
                    result.push_back(AlgebraicTerm(this->number ^ other.number,this->operation));
                }
                else{
                    result.reserve(2);
                    result.push_back(*this);
                    result.push_back(other);
                }
                return result;
            }
        public:
            AlgebraicTerm(){ }

            AlgebraicTerm(const StandardForm& number,const Operation& operation = Operation::NO_OPERATOR) noexcept{
                this->number = number;
                this->operation = operation;
            }

            AlgebraicTerm(const StandardForm& number,const Variables& variables,const Operation& operation) noexcept {
                this->number = number;
                this->variables = variables;
                this->operation = operation;
            }

            AlgebraicTerm(const Variables& variables,const Operation& operation = Operation::NO_OPERATOR) noexcept {
                this->variables = variables;
            }

            //TODO doesnt work correctly
            AlgebraicTerm(const std::string& term){
                bool operationFound = true;
                switch(term[0]){
                    case '+' :
                        this->operation = Operation::ADD;
                        break;
                    case '-' :
                        this->operation = Operation::SUBTRACT;
                        break;
                    case '*' :
                        this->operation = Operation::MULTIPLY;
                        break;
                    case '/' :
                        this->operation = Operation::DIVIDE;
                        break;
                    case '^' :
                        this->operation = Operation::POWER;
                        break;
                    default :
                        if(isdigit(term[0])) {
                            this->operation = Operation::ADD;
                            std::size_t i = 1;
                            while(i < term.length() && !isalpha(term[i])) {
                                i++;
                            }
                            this->number = term.substr(0, i);
                        } else {
                            operationFound = false;
                        }
                        break;
                }        
                const std::string s = operationFound ? term.substr(1) : term;
                std::cout << "String s : " << s << std::endl;
                auto x = s.find('(');
                std::cout << "x =  " << x << std::endl;
                if(x == (size_t)0){
                    auto y = s.find(')');
                    std::cout << "Number Substring : " << s.substr(x + 1,y - 1)<< std::endl;
                    this->number = StandardForm(s.substr(x + 1,y - 1));
                    std::cout <<"Number standardform : "<< this->number << std::endl;
                    this->variables = Variables(s.substr(y + 1));
                }
                else{
                    std::string num;
                    for(const char ch:s){
                        if(isdigit(ch) || ch == '.' || ch == '^'){ 
                            num += ch;
                            continue;
                        }
                        if(isalpha(ch)) break;
                    }
                    std::cout << "else .. num s : " <<num << std::endl;
                    this->number = StandardForm(num);
                    this->variables = Variables(s.substr(num.length()));
                }
            }

            StandardForm getNumber() const noexcept{
                return this->number;
            }

            Variables getVariables() const noexcept{
                return this->variables;
            }

            Operation getOperation() const noexcept{
                return this->operation;
            }

            std::string asString() const noexcept{
                return getOperationAsString(this->operation) + this->number.toAppropriateFormat() + this->variables.asString();
            }

            //TODO doenst work 
            AlgebraicTerm evaluteTermWithVariableValues(const Variables& variableData) const noexcept{
                StandardForm newNumber = StandardForm(1);
                Variables::mapType variableOhneValue;
                for(const auto& it:this->variables.getAll()){
                    if(variableData[it.first] == variableInMapNichtDa) variableOhneValue[it.first] = it.second;
                    else newNumber *= (variableData[it.first] ^ it.second);
                }
                return AlgebraicTerm(newNumber,variableOhneValue,this->operation);
            }

            std::vector<AlgebraicTerm> performOperationBetweenTerms(const AlgebraicTerm& term) const{
                switch(term.operation){
                    case Operation::NO_OPERATOR : throw std::invalid_argument("Can't perform operation when terms aren't connected to each other");
                    case Operation::ADD : return this->add(term) ;
                    case Operation::SUBTRACT : return this->minus(term);
                    case Operation::MULTIPLY : return this->multiply(term);
                    case Operation::DIVIDE : return this->divide(term);
                    case Operation::POWER : return this->power(term);
                }
            }

            friend std::ostream& operator<<(std::ostream& os, const AlgebraicTerm& term){
                os << term.asString();
                return os;
            }

            std::vector<AlgebraicTerm> operator+(const AlgebraicTerm& other) const{
                if(isAdditionSubtractionOrNoOperation(other.operation)) return this->add(other);
                throw std::invalid_argument("Can't add these 2 terms up :" + this->asString() + " ..." + other.asString());
            }

            std::vector<AlgebraicTerm> operator+(const Variables& other) const noexcept{
                return this->add(AlgebraicTerm(other));
            }

            std::vector<AlgebraicTerm> operator+(const StandardForm& other) const noexcept{
                return this->add(AlgebraicTerm(other));
            }

            std::vector<AlgebraicTerm> operator-(const AlgebraicTerm& other) const {
                if(isAdditionSubtractionOrNoOperation(other.operation)) return this->minus(other);
                throw std::invalid_argument("Can't add these 2 terms up :" + this->asString() + " ..." + other.asString());
            }
            std::vector<AlgebraicTerm> operator-(const Variables& other) const noexcept{
                return this->minus(AlgebraicTerm(other));
            }

            std::vector<AlgebraicTerm> operator-(const StandardForm& other) const noexcept{
                return this->minus(AlgebraicTerm(other));
            }
            std::vector<AlgebraicTerm> operator-() const {
                return this->minus((*this * 2).at(0));
            }

            std::vector<AlgebraicTerm> operator*(const AlgebraicTerm& other) const{
                if(isAdditionSubtractionOrNoOperation(other.operation)) return this->multiply(other);
                throw std::invalid_argument("Can't add these 2 terms up :" + this->asString() + " ..." + other.asString());
            }
            std::vector<AlgebraicTerm> operator*(const Variables& other) const noexcept{
                return this->multiply(AlgebraicTerm(other));
            }

            std::vector<AlgebraicTerm> operator*(const StandardForm& other) const noexcept{
                return this->multiply(AlgebraicTerm(other));
            }

            std::vector<AlgebraicTerm> operator/(const AlgebraicTerm& other) const{
                if(isAdditionSubtractionOrNoOperation(other.operation)) return this->divide(other);
                throw std::invalid_argument("Can't add these 2 terms up :" + this->asString() + " ..." + other.asString());
            }
            std::vector<AlgebraicTerm> operator/(const Variables& other) const noexcept{
                return this->divide(AlgebraicTerm(other));
            }
            std::vector<AlgebraicTerm> operator/(const StandardForm& other) const noexcept{
                return this->divide(AlgebraicTerm(other));
            }

            std::vector<AlgebraicTerm> operator^(const AlgebraicTerm& other) const{
                if(isAdditionSubtractionOrNoOperation(other.operation)  ) return this->power(other);
                throw std::invalid_argument("Can't add these 2 terms up :" + this->asString() + " ..." + other.asString());
            }
            std::vector<AlgebraicTerm> operator^(const Variables& other) const noexcept{
                return this->power(AlgebraicTerm(other));
            }
            std::vector<AlgebraicTerm> operator^(const StandardForm& other) const noexcept{
                return this->power(AlgebraicTerm(other));
            }

            bool operator==(const AlgebraicTerm& other) const noexcept{
                return (this->number == other.number) && (this->variables == other.variables) && (this->operation == other.operation);
            }

            bool operator==(const Variables& other) const noexcept{
                return *this == AlgebraicTerm(other);
            }

            bool operator==(const StandardForm& other) const noexcept{
                return *this == AlgebraicTerm(other);
            }

            bool operator!=(const AlgebraicTerm& other) const noexcept{
                return !(*this == other);
            }
            bool operator!=(const Variables& other) const noexcept{
                return *this == AlgebraicTerm(other);
            }

            bool operator!=(const StandardForm& other) const noexcept{
                return *this == AlgebraicTerm(other);
            }
    };

    class AlgebraicExpression{
        private:
            using listOfTerms = std::vector<AlgebraicTerm>;
            listOfTerms _terms;

            static bool termFoundInVector(const AlgebraicTerm& term, const std::vector<AlgebraicTerm>& terms) {
                return std::find(terms.begin(), terms.end(), term) != terms.end();
            }

            listOfTerms infixToPostfixConvertor() const {
                AlgebraicTerm keinOperationTerm = AlgebraicTerm();
                std::stack<AlgebraicTerm> operatorStack;

                listOfTerms postfix;
                postfix.reserve(this->_terms.size());

                bool foundNoOperatorTerm = false;
                for(const auto& term:this->_terms){
                    Operation operation = term.getOperation();
                    if(operation == Operation::NO_OPERATOR){
                        if(foundNoOperatorTerm) throw std::invalid_argument("Cant have more then 1 term not connected with a operation");
                        foundNoOperatorTerm = true;
                        keinOperationTerm = term;
                        continue;
                    }

                    while (!operatorStack.empty() && getOperationValue(term.getOperation()) <= getOperationValue(operatorStack.top().getOperation())) {
                        postfix.push_back(operatorStack.top());
                        operatorStack.pop();
                    }
                    operatorStack.push(term);
                }
                while (!operatorStack.empty()) {
                    postfix.push_back(operatorStack.top());
                    operatorStack.pop();
                }
                if(foundNoOperatorTerm) postfix.push_back(keinOperationTerm);
                return postfix;
            }

            //fucks up when expresison contains a no operation though it should be 'added' to the expresison at the front of it
            AlgebraicExpression evalutePostfixExpression(const std::vector<math::AlgebraicTerm>& postfix) const{
                std::stack<math::AlgebraicExpression> stack;

                for (const AlgebraicTerm& term : postfix) stack.push(AlgebraicExpression(term));

                while (stack.size() > 1) {
                    AlgebraicExpression term2 = stack.top();
                    stack.pop();
                    AlgebraicExpression term1 = stack.top();
                    stack.pop();
                    stack.push(term1.performOperationsBetweenExpressions(term2));
                }
                if (stack.size() != 1) throw std::invalid_argument("Invalid input: malformed expression");
                return stack.top(); 
            }

            AlgebraicExpression convertMapIntoExpression(const std::map<Variables,AlgebraicTerm>& combinedTermsMap) const noexcept{
                listOfTerms combinedTerms;
                combinedTerms.reserve(combinedTermsMap.size());
                for (const auto& term : combinedTermsMap) {
                    combinedTerms.push_back(term.second);
                }
                return AlgebraicExpression(combinedTerms);
            }

            AlgebraicExpression add(const AlgebraicExpression& expression) const noexcept{
                std::map<Variables, AlgebraicTerm> combinedTermsMap;
                // Combine terms from both expressions
                for (const auto& t1 : this->_terms) {
                    Variables variables = t1.getVariables();
                    combinedTermsMap[variables] = combinedTermsMap.count(variables) > 0 ? (combinedTermsMap[variables] + t1).at(0) : t1;
                }

                for (const auto& t2 : expression._terms) {
                    Variables variables = t2.getVariables();
                    combinedTermsMap[variables] = combinedTermsMap.count(variables) > 0 ? (combinedTermsMap[variables] + t2).at(0) : t2;
                }
                return convertMapIntoExpression(combinedTermsMap);
            }

            AlgebraicExpression subtract(const AlgebraicExpression& expression) const noexcept{
                std::map<Variables, AlgebraicTerm> combinedTermsMap;

                for (const auto& term : this->_terms) {
                    Variables variables = term.getVariables();
                    combinedTermsMap[variables] = combinedTermsMap.count(variables) > 0 ? (combinedTermsMap[variables] + term).at(0) : term;
                }

                for (const auto& term : expression._terms) {
                    Variables variables = term.getVariables();
                    combinedTermsMap[variables] = combinedTermsMap.count(variables) > 0 ? (combinedTermsMap[variables] - term).at(0) : (-term).at(0);
                }

                return convertMapIntoExpression(combinedTermsMap);
            }

            AlgebraicExpression multiply(const AlgebraicExpression& expression) const noexcept{
                std::map<Variables,AlgebraicTerm> combinedTermsMap;
                for(const auto& t1:this->_terms){
                    for(const auto& t2:this->_terms){
                        AlgebraicTerm product = (t1 * t2).at(0);
                        Variables productVariables = product.getVariables();
                        combinedTermsMap[productVariables] = combinedTermsMap.count(productVariables) > 0 ? (combinedTermsMap[productVariables] + product).at(0) : product;
                    }
                }
                return convertMapIntoExpression(combinedTermsMap);
            }

            AlgebraicExpression divide(const AlgebraicExpression& expression) const noexcept{
                
            }

            AlgebraicExpression power(const AlgebraicExpression& expression) const noexcept{
                
            }

            bool operator==(const AlgebraicExpression& other) const noexcept {
                if (this->_terms.size() != other._terms.size()) return false;
                for (const auto& term : this->_terms) {
                    if (!termFoundInVector(term, other._terms)) return false;
                }
                for (const auto& term : other._terms) {
                    if (!termFoundInVector(term, this->_terms)) return false;
                }

                return true;
            }
        public:
            AlgebraicExpression() noexcept{ }

            AlgebraicExpression(const listOfTerms& terms) noexcept{
                _terms.reserve(terms.size());
                this->_terms = terms;
            }

            AlgebraicExpression(const AlgebraicTerm& term) noexcept{
                _terms.reserve(1);
                this->_terms.push_back(term);
            }

            //TODO do it
            AlgebraicExpression(const std::string& terms) noexcept{
                
            }

            listOfTerms getTerms() const noexcept{
                return this->_terms;
            }

            Operation getConnectingOperation() const noexcept{
                return this->_terms.front().getOperation();
            }

            friend std::ostream& operator<<(std::ostream& os, const AlgebraicExpression& expression){
                os << expression.asString();
                return os;
            }

            std::string asString() const noexcept{
                std::string s = "";
                for(const AlgebraicTerm& term:this->_terms){
                    s += term.asString() + " ";
                }
                return s;
            }

            AlgebraicExpression calculate() const noexcept {
                return evalutePostfixExpression(infixToPostfixConvertor());
            }

            AlgebraicExpression performOperationsBetweenExpressions(const AlgebraicExpression& expression)  const {
                   switch(expression.getConnectingOperation()){
                    case Operation::NO_OPERATOR : throw std::invalid_argument("Can't perform operation when terms aren't connected to each other");
                    case Operation::ADD : return this->add(expression) ;
                    case Operation::SUBTRACT : return this->subtract(expression);
                    case Operation::MULTIPLY : return this->multiply(expression);
                    case Operation::DIVIDE : return this->divide(expression);
                    case Operation::POWER : return this->power(expression);
                }
            }

            AlgebraicExpression calculateExpressionWithVariableValues(const Variables& variableData) const noexcept{
                listOfTerms vector;
                vector.reserve(this->_terms.size());
                for(const AlgebraicTerm& term:this->_terms) vector.push_back(term.evaluteTermWithVariableValues(variableData));
                return AlgebraicExpression(vector).calculate();
            }

            AlgebraicExpression operator+(const AlgebraicExpression& other) const {
                if(isAdditionSubtractionOrNoOperation(other.getConnectingOperation())) return this->add(other);
                throw std::invalid_argument("Can't add these 2 expressions up :" + this->asString() + " ..." + other.asString());
            }
            AlgebraicExpression operator+(const AlgebraicTerm& other) const {
                if(isAdditionSubtractionOrNoOperation(other.getOperation())) return this->add(AlgebraicExpression(other));
                throw std::invalid_argument("Can't add these 2 expressions up :" + this->asString() + " ..." + other.asString());
            }
            AlgebraicExpression operator+(const StandardForm& other) const noexcept{
                return this->add(AlgebraicExpression(other));
            }

            void operator+=(const AlgebraicExpression& other){
                if(isAdditionSubtractionOrNoOperation(other.getConnectingOperation())) *this = this->add(other);
                throw std::invalid_argument("Can't add these 2 expressions up :" + this->asString() + " ..." + other.asString());
            }
            void operator+=(const AlgebraicTerm& other)  {
                if(isAdditionSubtractionOrNoOperation(other.getOperation())) *this = this->add(AlgebraicExpression(other));
                throw std::invalid_argument("Can't add these 2 expressions up :" + this->asString() + " ..." + other.asString());
            }
            void operator+=(const StandardForm& other) noexcept{
                *this = this->add(AlgebraicExpression(other));
            }

            AlgebraicExpression operator-(const AlgebraicExpression& other) const {
                if(isAdditionSubtractionOrNoOperation(other.getConnectingOperation())) return this->subtract(other);
                throw std::invalid_argument("Can't add these 2 expressions up :" + this->asString() + " ..." + other.asString());
            }
            AlgebraicExpression operator-(const AlgebraicTerm& other) const {
                Operation operation = other.getOperation();
                if(isAdditionSubtractionOrNoOperation(other.getOperation())) return this->subtract(AlgebraicExpression(other));
                throw std::invalid_argument("Can't add these 2 expressions up :" + this->asString() + " ..." + other.asString());
            }
            AlgebraicExpression operator-(const StandardForm& other) const noexcept{
                return this->subtract(AlgebraicExpression(other));
            }
            void operator-=(const AlgebraicExpression& other){
                if(isAdditionSubtractionOrNoOperation(other.getConnectingOperation())) *this = this->subtract(other);
                throw std::invalid_argument("Can't add these 2 expressions up :" + this->asString() + " ..." + other.asString());
            }
            void operator-=(const AlgebraicTerm& other)  {
                if(isAdditionSubtractionOrNoOperation(other.getOperation())) *this = this->subtract(AlgebraicExpression(other));
                throw std::invalid_argument("Can't add these 2 expressions up :" + this->asString() + " ..." + other.asString());
            }
            void operator-=(const StandardForm& other) noexcept{
                *this = this->subtract(AlgebraicExpression(other));
            }

            AlgebraicExpression operator*(const AlgebraicExpression& other) const {
                if(isAdditionSubtractionOrNoOperation(other.getConnectingOperation())) return this->multiply(other);
                throw std::invalid_argument("Can't add these 2 expressions up :" + this->asString() + " ..." + other.asString());
            }
            AlgebraicExpression operator*(const AlgebraicTerm& other) const {
                Operation operation = other.getOperation();
                if(isAdditionSubtractionOrNoOperation(other.getOperation())) return this->multiply(AlgebraicExpression(other));
                throw std::invalid_argument("Can't add these 2 expressions up :" + this->asString() + " ..." + other.asString());
            }
            AlgebraicExpression operator*(const StandardForm& other) const noexcept{
                return this->multiply(AlgebraicExpression(other));
            }
            void operator*=(const AlgebraicExpression& other){
                if(isAdditionSubtractionOrNoOperation(other.getConnectingOperation())) *this = this->multiply(other);
                throw std::invalid_argument("Can't add these 2 expressions up :" + this->asString() + " ..." + other.asString());
            }
            void operator*=(const AlgebraicTerm& other)  {
                if(isAdditionSubtractionOrNoOperation(other.getOperation())) *this = this->multiply(AlgebraicExpression(other));
                throw std::invalid_argument("Can't add these 2 expressions up :" + this->asString() + " ..." + other.asString());
            }
            void operator*=(const StandardForm& other) noexcept{
                *this = this->multiply(AlgebraicExpression(other));
            }

            AlgebraicExpression operator/(const AlgebraicExpression& other) const {
                if(isAdditionSubtractionOrNoOperation(other.getConnectingOperation())) return this->divide(other);
                throw std::invalid_argument("Can't add these 2 expressions up :" + this->asString() + " ..." + other.asString());
            }
            AlgebraicExpression operator/(const AlgebraicTerm& other) const {
                if(isAdditionSubtractionOrNoOperation(other.getOperation())) return this->divide(AlgebraicExpression(other));
                throw std::invalid_argument("Can't add these 2 expressions up :" + this->asString() + " ..." + other.asString());
            }
            AlgebraicExpression operator/(const StandardForm& other) const noexcept{
                return this->divide(AlgebraicExpression(other));
            }
            void operator/=(const AlgebraicExpression& other){
                if(isAdditionSubtractionOrNoOperation(other.getConnectingOperation())) *this = this->divide(other);
                throw std::invalid_argument("Can't add these 2 expressions up :" + this->asString() + " ..." + other.asString());
            }
            void operator/=(const AlgebraicTerm& other)  {
                if(isAdditionSubtractionOrNoOperation(other.getOperation())) *this = this->divide(AlgebraicExpression(other));
                throw std::invalid_argument("Can't add these 2 expressions up :" + this->asString() + " ..." + other.asString());
            }
            void operator/=(const StandardForm& other) noexcept{
                *this = this->divide(AlgebraicExpression(other));
            }

            AlgebraicExpression operator^(const AlgebraicExpression& other) const {
                if(isAdditionSubtractionOrNoOperation(other.getConnectingOperation())) return this->power(other);
                throw std::invalid_argument("Can't add these 2 expressions up :" + this->asString() + " ..." + other.asString());

            }
            AlgebraicExpression operator^(const AlgebraicTerm& other) const {
                Operation operation = other.getOperation();
                if(isAdditionSubtractionOrNoOperation(other.getOperation())) return this->power(AlgebraicExpression(other));
                throw std::invalid_argument("Can't add these 2 expressions up :" + this->asString() + " ..." + other.asString());
            }
            AlgebraicExpression operator^(const StandardForm& other) const noexcept{
                return this->power(AlgebraicExpression(other));
            }
            void operator^=(const AlgebraicExpression& other){
                if(isAdditionSubtractionOrNoOperation(other.getConnectingOperation())) *this = this->power(other);
                throw std::invalid_argument("Can't add these 2 expressions up :" + this->asString() + " ..." + other.asString());
            }
            void operator^=(const AlgebraicTerm& other)  {
                if(isAdditionSubtractionOrNoOperation(other.getOperation())) *this = this->power(AlgebraicExpression(other));
                throw std::invalid_argument("Can't add these 2 expressions up :" + this->asString() + " ..." + other.asString());
            }
            void operator^=(const StandardForm& other) noexcept{
                *this = this->power(AlgebraicExpression(other));
            }

            bool equals(const AlgebraicExpression& other,const bool calculateBeforeComparing = true) const noexcept {
                if(!calculateBeforeComparing) return *this == other;
                return this->calculate() == other.calculate();
            }
    };
    //TODO finsih and use it correctly
    class Fraction {
        private :
            AlgebraicExpression numerator;
            AlgebraicExpression denominator;
            Operation operation = Operation::NO_OPERATOR;

            static int findCorrespondingBracket(const std::string& str, int start) {
                int count = 1;
                for (int i = start + 1; i < str.size(); i++) {
                    if (str[i] == '(') count++;
                    else if (str[i] == ')') count--;
                    if (count == 0) return i;   
                }
                return -1; 
            }

            Fraction subtract(const Fraction& other) const noexcept{
                if(this->denominator.equals(other.denominator)) return Fraction(this->numerator - other.numerator,this->denominator);
                return Fraction(this->numerator * other.denominator - other.numerator * this->denominator,this->denominator * other.denominator);
            }

            Fraction add(const Fraction& other) const noexcept{
                if(this->denominator.equals(other.denominator)) return Fraction(this->numerator + other.numerator,this->denominator);
                return Fraction(this->numerator * other.denominator + other.numerator * this->denominator,this->denominator * other.denominator);
            }

            Fraction multiply(const Fraction& other) const noexcept{
                return Fraction(this->numerator * other.numerator,this->denominator * this->numerator);
            }

            Fraction divide(const Fraction& other) const noexcept{
                return this->multiply(Fraction(other.denominator,other.numerator));
            }
        public :
            Fraction() noexcept {  }
            
            Fraction(const std::string& fraction) {
                auto pos = fraction.find('(');
                if(pos == (size_t) 0){
                    auto x = findCorrespondingBracket(fraction,1);
                    this->numerator = AlgebraicExpression(fraction.substr(0,x - 1));
                    auto y = fraction.substr(x).find('/') == std::string::npos;
                    if(y) throw std::invalid_argument("Invalid Fraction :" + fraction);
                    this->denominator = AlgebraicExpression(fraction.substr(x + 2,fraction.length() - 2));
                }
                else{
                    auto y = fraction.find('/');
                    this->numerator = AlgebraicExpression(fraction.substr(0,y - 1));
                    this->denominator = AlgebraicExpression(fraction.substr(y + 1));
                }
            }

            Fraction(const AlgebraicExpression& numerator,const AlgebraicExpression& denominator = AlgebraicExpression()) noexcept{
                this->numerator = numerator;
                this->denominator = denominator;
            }

            Fraction(const AlgebraicTerm& numerator,const AlgebraicTerm& denominator = AlgebraicTerm()) noexcept {
                this->numerator = AlgebraicExpression(numerator);
                this->denominator = AlgebraicExpression(denominator);
            }

            Fraction(const StandardForm& numerator,const StandardForm& denominator = StandardForm()) noexcept {
                this->numerator = AlgebraicExpression(AlgebraicTerm(numerator));
                this->denominator = AlgebraicExpression(AlgebraicTerm(denominator));
            }

            std::string asString() const noexcept{
                return "(" + this->numerator.asString() + ")/(" + this->denominator.asString();
            }

            friend std::ostream& operator<<(std::ostream& os, const Fraction& fraction) noexcept{
                os << fraction.asString();
                return os;
            }

            Fraction operator-(const Fraction& other) const{
                if(other.operation == Operation::ADD || other.operation == Operation::SUBTRACT) return this->subtract(other);
                throw std::invalid_argument("Can't add these 2 fractions up :" + this->asString() + " ..." + other.asString());
            }
            Fraction operator-(const AlgebraicExpression& other) const {
                if(other.getConnectingOperation() == Operation::ADD || other.getConnectingOperation() == Operation::SUBTRACT) return this->subtract(other);
                throw std::invalid_argument("Can't add these 2 fractions up :" + this->asString() + " ..." + other.asString());
            }
            Fraction operator-(const AlgebraicTerm& other) const {
                if(other.getOperation() == Operation::ADD || other.getOperation() == Operation::SUBTRACT) return this->subtract(Fraction(other));
                throw std::invalid_argument("Can't add these 2 fractions up :" + this->asString() + " ..." + other.asString());
            }
            Fraction operator-(const StandardForm& other) const noexcept{
                return this->subtract(Fraction(other));
            }
            Fraction operator-(const double& other) const noexcept{
                return this->subtract(Fraction(other));
            }

            Fraction operator+(const Fraction& other) const {
                if(other.operation == Operation::ADD || other.operation == Operation::SUBTRACT) return this->add(other);
                throw std::invalid_argument("Can't add these 2 fractions up :" + this->asString() + " ..." + other.asString());
            }
            Fraction operator+(const AlgebraicExpression& other) const {
                if(other.getConnectingOperation() == Operation::ADD || other.getConnectingOperation() == Operation::SUBTRACT) return this->add(other);
                throw std::invalid_argument("Can't add these 2 fractions up :" + this->asString() + " ..." + other.asString());
            }
            Fraction operator+(const AlgebraicTerm& other) const{
                if(other.getOperation() == Operation::ADD || other.getOperation() == Operation::SUBTRACT) return this->add(Fraction(other));
                throw std::invalid_argument("Can't add these 2 fractions up :" + this->asString() + " ..." + other.asString());
            }
            Fraction operator+(const StandardForm& other) const noexcept{
                return this->add(Fraction(other));
            }
            Fraction operator+(const double& other) const noexcept{
                return this->add(Fraction(other));
            }

            Fraction operator*(const Fraction& other) const {
                if(other.operation == Operation::ADD || other.operation == Operation::SUBTRACT) return this->multiply(other);
                throw std::invalid_argument("Can't add these 2 fractions up :" + this->asString() + " ..." + other.asString());
            }
            Fraction operator*(const AlgebraicExpression& other) const {
                if(other.getConnectingOperation() == Operation::ADD || other.getConnectingOperation() == Operation::SUBTRACT) return this->multiply(other);
                throw std::invalid_argument("Can't add these 2 fractions up :" + this->asString() + " ..." + other.asString());
            }
            Fraction operator*(const AlgebraicTerm& other) const {
                if(other.getOperation() == Operation::ADD || other.getOperation() == Operation::SUBTRACT) return this->multiply(Fraction(other));
                throw std::invalid_argument("Can't add these 2 fractions up :" + this->asString() + " ..." + other.asString());
            }
            Fraction operator*(const StandardForm& other) const noexcept{
                return this->multiply(Fraction(other));
            }
            Fraction operator*(const double& other) const noexcept{
                return this->multiply(Fraction(other));
            }

            Fraction operator/(const Fraction& other) const {
                if(other.operation == Operation::ADD || other.operation == Operation::SUBTRACT) return this->divide(other);
                throw std::invalid_argument("Can't add these 2 fractions up :" + this->asString() + " ..." + other.asString());
            }
            Fraction operator/(const AlgebraicExpression& other) const {
                if(other.getConnectingOperation() == Operation::ADD || other.getConnectingOperation() == Operation::SUBTRACT) return this->divide(other);
                throw std::invalid_argument("Can't add these 2 fractions up :" + this->asString() + " ..." + other.asString());
            }
            Fraction operator/(const AlgebraicTerm& other) const {
                if(other.getOperation() == Operation::ADD || other.getOperation() == Operation::SUBTRACT) return this->divide(Fraction(other));
                throw std::invalid_argument("Can't add these 2 fractions up :" + this->asString() + " ..." + other.asString());
            }
            Fraction operator/(const StandardForm& other) const noexcept{
                return this->divide(Fraction(other));
            }
            Fraction operator/(const double& other) const noexcept{
                return this->divide(Fraction(other));
            }
    };
}