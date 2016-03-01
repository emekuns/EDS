CC = g++
CFLAGS =

eds: main.o ArrivalEvent.o Burst.o CompleteCPUEvent.o CompleteIOEvent.o Event.o ExitEvent.o ListItem.o Node.o PriorityQueue.o Process.o Queue.o Simulation.o StartCPUEvent.o StartIOEvent.o TimeOutEvent.o
	$(CC) $(CFLAGS) -o eds main.o ArrivalEvent.o Burst.o CompleteCPUEvent.o CompleteIOEvent.o Event.o ExitEvent.o ListItem.o Node.o PriorityQueue.o Process.o Queue.o Simulation.o StartCPUEvent.o StartIOEvent.o TimeOutEvent.o

main.o: ArrivalEvent.h Burst.h CompleteCPUEvent.h CompleteIOEvent.h Event.h ExitEvent.h ListItem.h Node.h PriorityQueue.h Process.h Queue.h Simulation.h StartCPUEvent.h StartIOEvent.h TimeOutEvent.h

ArrivalEvent.o: ArrivalEvent.h Simulation.h

Burst.o: Burst.h

CompleteCPUEvent.o: CompleteCPUEvent.h Simulation.h

CompleteIOEvent.o: CompleteIOEvent.h Simulation.h

Event.o: Event.h ArrivalEvent.h TimeOutEvent.h

ExitEvent.o: ExitEvent.h Simulation.h

ListItem.o: ListItem.h

Node.o: Node.h

PriorityQueue.o: PriorityQueue.h

Process.o: Process.h Simulation.h

Queue.o: Queue.h

Simulation.o: Simulation.h Event.h ArrivalEvent.h TimeOutEvent.h StartCPUEvent.h StartIOEvent.h CompleteCPUEvent.h CompleteIOEvent.h ExitEvent.h

StartCPUEvent.o: StartCPUEvent.h Simulation.h

StartIOEvent.o: StartIOEvent.h Simulation.h

TimeOutEvent.o: TimeOutEvent.h Simulation.h

clean:
	rm -f *.o eds