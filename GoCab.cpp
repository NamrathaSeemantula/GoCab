#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define f first
#define s second

class Queue
{
private:
    int arr[100];
    int front = -1;
    int rear = -1;
    int size = 0;

public:
    void enqueue(int x)
    {
        if (rear == 100 - 1)
            return;
        else if (front == -1 and rear == -1)
        {
            front = rear = 0;
            arr[rear] = x;
        }
        else
        {
            arr[++rear] = x;
        }
        size++;
    }

    int dequeue()
    {
        int x;
        if (front == -1 and rear == -1)
            return -1;
        else if (front == rear)
        {
            x = arr[front];
            front = -1;
            rear = -1;
        }
        else
        {
            x = arr[front];
            front++;
        }
        size--;
        return x;
    }

    int top()
    {
        if (front == -1 and rear == -1)
            return -1;
        return arr[front];
    }

    void display()
    {
        if (rear == -1 and rear == front)
            return;

        for (int i = front; i <= rear; i++)
            cout << arr[i] << " ";
        cout << endl;
    }

    int getSize()
    {
        return size;
    }
};

class Maps
{
private:
    vector<pair<int, int>> adj[21]; // {v,weight}
    map<string, int> locations;
    map<int, string> locations1;
    vector<Queue> drivers;

public:
    Maps()
    {
        drivers.resize(21);
        drivers[5].enqueue(2010982);
        drivers[5].enqueue(2010983);
        drivers[8].enqueue(2010984);
        drivers[8].enqueue(2010985);
        drivers[20].enqueue(2010986);

        adj[1] = {{2, 3}, {3, 4}, {4, 5}, {5, 6}}; // {v,w}
        adj[2] = {{1, 3}, {3, 4}, {6, 5}, {7, 2}};
        adj[3] = {{1, 4}, {2, 4}, {4, 4}, {7, 1}, {8, 3}, {9, 3}};
        adj[4] = {{1, 5}, {3, 4}, {5, 7}, {9, 1}, {10, 3}, {11, 1}};
        adj[5] = {{1, 6}, {4, 7}, {11, 2}};
        adj[6] = {{2, 5}, {7, 2}, {12, 8}};
        adj[7] = {{2, 2}, {3, 1}, {6, 2}, {8, 3}, {9, 6}, {12, 4}, {13, 9}};
        adj[8] = {{3, 3}, {7, 3}, {9, 9}, {12, 4}, {13, 5}, {14, 1}};
        adj[9] = {{3, 3}, {4, 1}, {7, 6}, {8, 9}, {10, 4}, {14, 1}, {15, 4}};
        adj[10] = {{4, 3}, {9, 4}, {11, 3}, {15, 9}, {16, 9}, {19, 7}};
        adj[11] = {{4, 1}, {5, 2}, {10, 3}, {16, 1}};
        adj[12] = {{6, 8}, {7, 4}, {8, 4}, {13, 9}, {17, 1}};
        adj[13] = {{7, 9}, {8, 5}, {12, 9}, {14, 2}, {17, 3}, {18, 3}};
        adj[14] = {{8, 1}, {9, 1}, {13, 2}, {15, 3}, {18, 4}, {20, 2}};
        adj[15] = {{9, 4}, {10, 9}, {14, 3}, {16, 3}, {19, 1}, {20, 9}};
        adj[16] = {{10, 9}, {11, 1}, {15, 3}, {19, 5}};
        adj[17] = {{12, 1}, {13, 3}, {18, 2}};
        adj[18] = {{13, 3}, {14, 4}, {17, 2}, {20, 1}};
        adj[19] = {{10, 7}, {15, 1}, {16, 5}, {20, 4}};
        adj[20] = {{14, 2}, {15, 9}, {18, 1}, {19, 4}};

        locations["marina beach"] = 1;
        locations["guindy"] = 2;
        locations["besant nagar"] = 3;
        locations["royapuram"] = 4;
        locations["mylapore"] = 5;
        locations["anna nagar"] = 6;
        locations["kk nagar"] = 7;
        locations["adyar"] = 8;
        locations["gandhi nagar"] = 9;
        locations["indira nagar"] = 10;
        locations["kundrathur"] = 11;
        locations["kovur"] = 12;
        locations["porur"] = 13;
        locations["ponanmalle"] = 14;
        locations["krmm"] = 15;
        locations["ssn"] = 16;
        locations["thiruvanmiyur"] = 17;
        locations["T nagar"] = 18;
        locations["broadway"] = 19;
        locations["koyambedu"] = 20;

        locations1[1] = "marina beach";
        locations1[2] = "guindy";
        locations1[3] = "besant nagar";
        locations1[4] = "royapuram";
        locations1[5] = "mylapore";
        locations1[6] = "anna nagar";
        locations1[7] = "kk nagar";
        locations1[8] = "adyar";
        locations1[9] = "gandhi nagar";
        locations1[10] = "indira nagar";
        locations1[11] = "kundrathur";
        locations1[12] = "kovur";
        locations1[13] = "porur";
        locations1[14] = "ponanmalle";
        locations1[15] = "krmm";
        locations1[16] = "ssn";
        locations1[17] = "thiruvanmiyur";
        locations1[18] = "T nagar";
        locations1[19] = "broadway";
        locations1[20] = "koyambedu";
    }

    vector<int> dijkstra(int src)
    {

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(21, INT_MAX);

        pq.push({0, src});

        while (!pq.empty())
        {
            int prevNode = pq.top().second;
            int prevDist = pq.top().first;
            pq.pop();
            for (auto it : adj[prevNode])
            {
                int nextNode = it.first;
                int nextDist = it.second;

                if (dist[nextNode] > prevDist + nextDist)
                {
                    dist[nextNode] = prevDist + nextDist;
                    pq.push({dist[nextNode], nextNode});
                }
            }
        }

        return dist;
    }

    int getLocationId(string s)
    {
        return locations[s];
    }

    string getLocation(int s)
    {
        return locations1[s];
    }

    vector<int> getDriverId(vector<int> &tmp, int src, int dest)
    {
        vector<pair<int, int>> distPair;
        for (int i = 1; i <= 20; i++)
        {
            distPair.pb({tmp[i], i});
        }

        sort(distPair.begin(), distPair.end()); // sorting the distance
        vector<int> t;
        for (int i = 0; i < distPair.size(); i++)
        {
            if (drivers[distPair[i].second].getSize() > 0)
            {
                t = {distPair[i].second, drivers[distPair[i].second].top()};
                int val = drivers[distPair[i].second].top();
                drivers[distPair[i].second].dequeue();
                // cout << "id is " << val << " dest is " << dest << endl;
                drivers[dest].enqueue(val);
                return t;
            }
        }

        return t;
    }

    void printGraph()
    {
        cout << "printing the graph " << endl;
        queue<int> q;
        int src = 1;
        vector<int> vis(21, 0);
        q.push(src);
        vis[src] = 1;
        cout << "u"
             << " "
             << "v"
             << " "
             << "w" << endl;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            for (auto it : adj[node])
            {
                if (vis[it.f] == 0)
                {
                    cout << node << " " << it.f << " " << it.s << endl;
                    q.push(it.f);
                    vis[it.f] = 1;
                }
            }
        }
        cout << endl;
    }

    void printLocationId()
    {
        cout << "printing location and locationID " << endl
             << endl;
        cout << "loaction "
             << " "
             << "loactionId" << endl
             << endl;
        for (auto it : locations)
        {
            cout << it.f << " " << it.s << endl;
        }
        cout << endl;
    }

    void printDrivers()
    {
        cout << "printing the drivers in each location " << endl;
        for (int i = 1; i <= 20; i++)
        {
            cout << locations1[i] << " : ";
            if (drivers[i].getSize() == 0)
            {
                cout << "No drivers are available in this location now " << endl;
            }
            else
            {
                drivers[i].display();
            }
            cout << endl;
        }
    }

    void printLocationId1()
    {
        cout << "printing location and locationID " << endl
             << endl;
        cout << "locationId"
             << " "
             << "location" << endl
             << endl;
        for (auto it : locations1)
        {
            cout << it.f << " " << it.s << endl;
        }
        cout << endl;
    }
};

class Node
{
public:
    int driverId;
    string driverName;
    long long driverNumber;
    int driverRating;
    Node *left;
    Node *right;
    int height;
};

class Driver
{
private:
    Node *root;

public:
    Driver()
    {
        root = NULL;
        insertValue(2010982, "Ramesh", 9840550829, 5);
        insertValue(2010983, "Suresh", 9841655082, 3);
        insertValue(2010984, "Karthick", 9087809420, 4);
        insertValue(2010985, "Ajith", 8608191811, 2);
        insertValue(2010986, "Rahul", 987654321, 4);
    }

    int height(Node *N)
    {
        if (N == NULL)
            return 0;
        return N->height;
    }
    int max(int a, int b)
    {
        return (a > b) ? a : b;
    }

    Node *newNode(int _driverId, string _driverName, long long _driverNumber, int _driverRating)
    {
        Node *node = new Node();
        node->driverId = _driverId;
        node->driverName = _driverName;
        node->driverNumber = _driverNumber;
        node->driverRating = _driverRating;
        node->left = NULL;
        node->right = NULL;
        node->height = 1;
        return (node);
    }

    Node *rightRotate(Node *y)
    {
        Node *x = y->left;
        Node *T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = max(height(y->left), height(y->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;
        return x;
    }

    Node *leftRotate(Node *x)
    {
        Node *y = x->right;
        Node *T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;
        return y;
    }

    int getBalance(Node *N)
    {
        if (N == NULL)
            return 0;
        return height(N->left) - height(N->right);
    }

    Node *insert(Node *node, int driverId, string driverName, long long driverNumber, int driverRating)
    {
        if (node == NULL)
            return (newNode(driverId, driverName, driverNumber, driverRating));

        if (driverId < node->driverId)
            node->left = insert(node->left, driverId, driverName, driverNumber, driverRating);
        else if (driverId > node->driverId)
            node->right = insert(node->right, driverId, driverName, driverNumber, driverRating);
        else
            return node;

        node->height = 1 + max(height(node->left), height(node->right));

        int balance = getBalance(node);

        if (balance > 1 && driverId < node->left->driverId)
            return rightRotate(node);

        if (balance < -1 && driverId > node->right->driverId)
            return leftRotate(node);

        if (balance > 1 && driverId > node->left->driverId)
        {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        if (balance < -1 && driverId < node->right->driverId)
        {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    void insertValue(int driverId, string driverName, long long driverNumber, int driverRating)
    {
        root = insert(root, driverId, driverName, driverNumber, driverRating);
    }

    Node *search(Node *root, int driverId)
    {
        if (root == NULL)
        {
            return root;
        }
        if (root->driverId == driverId)
        {
            return root;
        }

        if (driverId > root->driverId)
            return search(root->right, driverId);
        else
            return search(root->left, driverId);
    }

    Node *searchValue(int driverId)
    {
        return search(root, driverId);
    }

    void preOrder(Node *node)
    {
        if (node != NULL)
        {
            cout << "driverId is " << node->driverId << endl;
            cout << "driverName is " << node->driverName << endl;
            cout << "driverNumber is " << node->driverNumber << endl;
            cout << "driver Rating is " << node->driverRating << endl;
            cout << endl;

            preOrder(node->left);
            preOrder(node->right);
        }
    }
    void printTree()
    {
        cout << "\nPrinting the Drivers information in the Tree " << endl
             << endl;
        preOrder(root);
    }
};

class Hash
{
private:
    map<string, pair<string, string>> mp; // {userId,{password,username}}

public:
    void insert(string userId, string password, string userName)
    {
        mp[userId] = {password, userName};
    }

    bool checkUser(string userId)
    {
        if (mp.find(userId) == mp.end())
            return false;
        return true;
    }

    bool checkPassword(string userId, string password)
    {
        if (mp[userId].first != password)
            return false;
        return true;
    }

    string getUserName(string userId)
    {
        return mp[userId].second;
    }
};

void SignUp(Hash &hash)
{
    cout << "----------------------------------------------------------------------------------------SIGIN UP PAGE----------------------------------------------------------------------------------------------------\n\n";

    string userId, userName, password;
    cout << "Enter the username : ";
    cin >> userName;
    cout << endl;

    while (true)
    {
        cout << "Enter userId : ";
        cin >> userId;
        cout << endl;
        if (hash.checkUser(userId) == true)
        {
            cout << "UserId is already taken Enter a unique userId";
            cout << endl;
            continue;
        }
        break;
    }

    cout << "Enter the password : ";
    cin >> password;
    cout << endl;
    hash.insert(userId, password, userName);
}

void cabBookingPage()
{
    Maps maps;
    Driver driver;
    cout << "----------------------------------------------------------------------------------------CAB BOOKING PAGE-------------------------------------------------------------------------------------------------------\n\n";

    while (true)
    {
        // string newl;
        // cin >> newl;
        string src, dest;
        cout << "Enter the source : ";
        getline(cin, src);
        cout << endl;
        cout << "Enter the destination : ";
        getline(cin, dest);
        cout << endl;
        vector<int> dist(21);

        dist = maps.dijkstra(maps.getLocationId(src));
        cout << "Current Loaction is : " << src << endl
             << endl;
        cout << "Destination is : " << dest << endl
             << endl;
        cout << "The distance between " << src << " and " << dest << " is " << dist[maps.getLocationId(dest)] << " kms " << endl
             << endl;
        cout << "Fare is : " << dist[maps.getLocationId(dest)] * 100 << endl
             << endl;

        cout << "Confirm Booking ???" << endl
             << endl;
        cout << "Enter yes for confirm booking else no " << endl
             << endl;
        string ch;
        cout << "Enter the choice : " << ch;
        cin >> ch;

        if (ch == "YES" or ch == "yes")
        {
            srand(time(NULL));
            int lower = 1000, upper = 9999;
            int otp = (rand() % (upper - lower + 1)) + lower;
            vector<int> vec = maps.getDriverId(dist, maps.getLocationId(src), maps.getLocationId(dest));
            // cout << "Driver Id is " << vec[1] << " driver's locations " << maps.getLocation(vec[0]) << endl;
            Node *node = driver.searchValue(vec[1]);
            cout << "Driver Id is : " << node->driverId << endl
                 << endl;
            cout << "Driver's location : " << maps.getLocation(vec[0]) << endl
                 << endl;
            cout << "Driver Name is : " << node->driverName << endl
                 << endl;
            cout << "Driver Number is : " << node->driverNumber << endl
                 << endl;
            cout << "Driver's Rating is : " << node->driverRating << endl
                 << endl;
            cout << "Dist between your current loctaion and driver's location " << dist[vec[0]] << " km " << endl
                 << endl;
            cout << "Driver will reach within " << dist[vec[0]] * 3 << " minutes " << endl
                 << endl;
            cout << "OTP number is " << otp << endl
                 << endl;
        }
        else
        {
            getchar();
            continue;
        }

        cout << "Your driver is arriving " << endl;
        cout << "Do you want to cancel the ride " << endl
             << endl;
        cout << "Enter yes to cancel " << endl
             << endl;
        string ch1;
        cin >> ch1;
        if (ch1 == "yes" or ch1 == "YES")
        {
            cout << "Your ride is cancelled " << endl;
            break;
        }
        else
        {
            cout << "Your driver is arriving " << endl;
            break;
        }
    }
}

void Login(Hash &hash)
{
    cout << "----------------------------------------------------------------------------------------LOGIN PAGE-------------------------------------------------------------------------------------------------------\n\n";

    while (true)
    {
        string userId, userName, password;
        cout << "Enter the UserId : ";
        cin >> userId;
        cout << endl;
        cout << "Enter the password : ";
        cin >> password;
        cout << endl;

        if (!hash.checkUser(userId))
        {
            cout << "Account not found\n";
            SignUp(hash);
            cout << "----------------------------------------------------------------------------------------LOGIN PAGE-------------------------------------------------------------------------------------------------------\n\n";
            continue;
        }

        else if (!hash.checkPassword(userId, password))
        {
            cout << "Incorrect Password\n";
            continue;
        }
        break;
    }

    getchar();
    cabBookingPage();
}

void Testing()
{
    Maps maps;
    Driver driver;

    maps.printGraph();
    maps.printLocationId();
    maps.printLocationId1();
    maps.printDrivers();
    driver.printTree();
    // insertValue(2010982, "Ramesh", 9840550829, 5);
    driver.insertValue(200000, "namratha", 99999999, 4);
    driver.printTree();
}

int main()
{
    Hash hash;
    Login(hash);

    Testing();
}
