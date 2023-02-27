#include <stdio.h>
#include <mosquitto.h>

int main()
{
    // Initialize library
    mosquitto_lib_init();

    /*
     * struct mosquitto
     *  - data type used for saving mosquitto client instance
     *  - mosquitto client instance contains all the information of the client
     *    so we can communicate with it
     *
     * mosquitto_new(
            <client_id>,
            <clean_sesion_flag>,
            <user_name_and_password_enable>
        ) -> mosquitto_client_instance
     */
    struct mosquitto* mosq = mosquitto_new("publisher-test", true, NULL);

    /*
     * mosquitto_connect(
            <mosquitto_client_instance>,
            <broker name or IP address>,
            <broker port number>,
            <lifetime>
        ) -> int
     */
    int rc = mosquitto_connect(mosq, "localhost", 1883, 60);
    if (rc != 0) {
        printf("Client could not connect to broker! Error Code: %d\n", rc);
        mosquitto_destroy(mosq);
        return -1;
    }

    printf("We are now connected to the broker!\n");

    /*
     * mosquitto_publish(
            <mosquitto_client_instance>,
            <pointer to a message id>,
            <topic under which we will publish the message>,
            <payload length in bites>,
            <message>
            <level of quality of service>,
            <retrain>
        )
        - message and payload presents the same thing
     */
    mosquitto_publish(mosq, NULL, "test/t1", 6, "Hello", 0, false);

    // Disconnect previously connected mosquitto client instance
    mosquitto_disconnect(mosq);

    // Destroy previously created mosquitto client instance
    mosquitto_destroy(mosq);

    // Clean previously initialized mosquitto library
    mosquitto_lib_cleanup();

    return 0;
}