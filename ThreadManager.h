#ifndef SKI_LIFT_THREADSTATW_H
#define SKI_LIFT_THREADSTATW_H

#include "QueueElement.h"
#include "MessageType.h"
#include <vector>

using namespace std;

class ThreadManager {
public:
    ThreadManager(int rank, int size, int myWeight, vector<int> tabAcks, vector<QueueElement> &queue);

    ThreadManager();

    ThreadManager(int rank, int size);

    int getRank();

    void setRank(int rank);

    int getSize();

    void setSize(int size);

    int getMyWeight();

    void setMyWeight(int myWeight);

    vector<QueueElement> &getQueue();

    void setQueue(vector<QueueElement> &queue);

    vector<int> &getTabAcks();

    void setTabAcks(vector<int> &tabAcks);

    void initTabAcks();

    static const int MSG_SIZE = 2;

    static const int CAPACITY = 500;

    void increaseClock();

    int *constructMessage();

private:
    int rank;
    int size;
    int myWeight;
    int clock;
    vector<int> tabAcks;
    vector<QueueElement> queue;
    bool IsMyRank(QueueElement o);

public:
    int getClock() const;

    void sendMessageForEverybody(int *msg, MessageType type);

    void addOwnRequestToQueue();

    void addRequestToQueue(QueueElement element);

    void sortQueue();

    bool isEveryAck();

    bool isEnoughPlaceOnLift();

    void clearAcks();

    void removeYourselfFromQueue();
};


#endif //SKI_LIFT_THREADSTATW_H
