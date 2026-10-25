#include <stdio.h>
#define BUFFER_SIZE 8

typedef struct
{
   char buffer[BUFFER_SIZE];
   int head;
   int tail;
   int count;
} CircularBuffer;

CircularBuffer tx_buf = {.head = 0, .tail = 0, .count = 0};
CircularBuffer rx_buf = {.head = 0, .tail = 0, .count = 0};

int is_buffer_full(CircularBuffer *cb)
{
   return cb->count == BUFFER_SIZE;
}

int is_buffer_empty(CircularBuffer *cb)
{
   return cb->count == 0;
}

int enqueue(CircularBuffer *cb, char data)
{
   if (is_buffer_full(cb))
   {
      return 0;
   }
   cb->buffer[cb->head] = data;
   cb->head = (cb->head + 1) % BUFFER_SIZE;
   cb->count++;
   return 1;
}

int dequeue(CircularBuffer *cb, char *data)
{
   if (is_buffer_empty(cb))
   {
      return 0;
   }
   *data = cb->buffer[cb->tail];
   cb->tail = (cb->tail + 1) % BUFFER_SIZE;
   cb->count--;
   return 1;
}

void uart_send(char ch)
{
   char transmitted_byte;
   if (enqueue(&tx_buf, ch))
   {
      printf("Enqueued '%c' to TX buffer\n", ch);
      if (dequeue(&tx_buf, &transmitted_byte))
      {
         printf("Transmitted: '%c'\n", transmitted_byte);
         if (enqueue(&rx_buf, transmitted_byte))
         {
            printf("Received into RX buffer\n");
         }
         else
         {
            printf("RX buffer full\n");
         }
      }
   }
   else
   {
      printf("TX buffer full\n");
   }
}

void uart_receive()
{
   char received_byte;
   if (dequeue(&rx_buf, &received_byte))
   {
      printf("Read from RX buffer: '%c'\n", received_byte);
   }
   else
   {
      printf("RX buffer is empty\n");
   }
}

void display_status()
{
   int i, index;
   printf("TX Buffer: %d/%d bytes\n", tx_buf.count, BUFFER_SIZE);
   printf("RX Buffer: %d/%d bytes\n", rx_buf.count, BUFFER_SIZE);
   if (!is_buffer_empty(&rx_buf))
   {
      printf("Data in RX Buffer: ");
      for (i = 0; i < rx_buf.count; i++)
      {
         index = (rx_buf.tail + i) % BUFFER_SIZE;
         printf("%c ", rx_buf.buffer[index]);
      }
      printf("\n");
   }
}

int main()
{
   int choice;
   char ch;
   while (1)
   {
      printf("\n1. Transmit byte\n");
      printf("2. Receive byte\n");
      printf("3. Display Buffer Status\n");
      printf("4. Exit\n");
      printf("Enter choice: ");
      scanf("%d", &choice);
      switch (choice)
      {
         case 1:
            printf("Enter character to transmit: ");
            scanf(" %c", &ch);
            uart_send(ch);
            break;
         case 2:
            uart_receive();
            break;
         case 3:
            display_status();
            break;
         case 4:
            return 0;
         default:
            printf("Invalid choice\n");
      }
   }
   return 0;
}
