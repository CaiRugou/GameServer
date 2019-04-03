// ����RUDP���մ���Buffer;

#ifndef __RUDP_RECV_BUFFER_H_
#define __RUDP_RECV_BUFFER_H_

#include "rudp_channel_interface.h"
#include "rudp_segment.h"

#include <map>
#include <list>

BASE_NAMESPACE_BEGIN_DECL

typedef map<uint64_t, RUDPRecvSegment*> RecvWindowMap;
typedef list<RUDPRecvSegment*>	RecvDataList;

typedef map<uint64_t, uint64_t>	LossIDTSMap;

class RUDPCCCObject;

class RUDPRecvBuffer
{
public:
    RUDPRecvBuffer();
    virtual~RUDPRecvBuffer();

    void                reset();
    //���������е�����;
    int32_t             on_data(uint64_t seq, const uint8_t* data, int32_t data_size);
    //��ʱ;
    void                on_timer(uint64_t now_timer, uint32_t rtc, uint32_t rtt);
    //��ȡBUFFER�е�����;
    int32_t             read(uint8_t* data, int32_t data_size);

    uint64_t            get_ack_id() const { return first_seq_;};

    uint32_t            get_bandwidth();

    void                set_net_channel(IRUDPNetChannel* channel) {net_channel_ = channel;};
    void                set_send_last_ack_ts(uint64_t ts) {last_ack_ts_ = ts;  recv_new_packet_ = false;};

    //ֻ�������յ��Է�����ʱ����һ��;
    void                set_first_seq(uint64_t first_seq) {first_seq_ = first_seq - 1; max_seq_ = first_seq_;};

    void                check_buffer();
    int32_t             get_buffer_data_size();

protected:
    void                check_recv_window();
    bool                check_loss();

protected:

    IRUDPNetChannel*    net_channel_;
    //���մ���;
    RecvWindowMap       recv_window_;
    //����ɵ���������Ƭ;
    RecvDataList        recv_data_;
    //��������;
    LossIDTSMap         loss_map_;

    //��ǰBUFFER�������������Ƭ��SEQ;
    uint64_t            first_seq_;
    //����BUFFER���ܵ�����������ƬID;
    uint64_t            max_seq_;
    //���һ�η���ACK��ʱ��;
    uint64_t            last_ack_ts_;
    //���ϴη���ACK�����ڣ��ܵ��µ��������ĵı�־;
    bool                recv_new_packet_;
    int                 ok_count_;

    uint32_t            bandwidth_;
    uint64_t            bandwidth_ts_;
    uint32_t            rtc_;
    uint32_t            rtt_;
};

BASE_NAMESPACE_END_DECL

#endif