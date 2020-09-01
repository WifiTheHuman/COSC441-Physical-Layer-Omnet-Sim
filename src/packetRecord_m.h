//
// Generated file, do not edit! Created by nedtool 6.0 from packetRecord.msg.
//

#ifndef __PACKETRECORD_M_H
#define __PACKETRECORD_M_H

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wreserved-id-macro"
#endif
#include <omnetpp.h>

// nedtool version check
#define MSGC_VERSION 0x0600
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of nedtool: 'make clean' should help.
#endif



class packetRecord;
/**
 * Class generated from <tt>packetRecord.msg:19</tt> by nedtool.
 * <pre>
 * //
 * // TODO generated message class
 * //
 * packet packetRecord
 * {
 *     int ovhdBits;
 *     int userBits;
 *     bool errorFlag = false;
 * 
 *     int sequenceNumber;
 * }
 * </pre>
 */
class packetRecord : public ::omnetpp::cPacket
{
  protected:
    int ovhdBits = 0;
    int userBits = 0;
    bool errorFlag = false;
    int sequenceNumber = 0;

  private:
    void copy(const packetRecord& other);

  protected:
    bool operator==(const packetRecord&) = delete;

  public:
    packetRecord(const char *name=nullptr, short kind=0);
    packetRecord(const packetRecord& other);
    virtual ~packetRecord();
    packetRecord& operator=(const packetRecord& other);
    virtual packetRecord *dup() const override {return new packetRecord(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual int getOvhdBits() const;
    virtual void setOvhdBits(int ovhdBits);
    virtual int getUserBits() const;
    virtual void setUserBits(int userBits);
    virtual bool getErrorFlag() const;
    virtual void setErrorFlag(bool errorFlag);
    virtual int getSequenceNumber() const;
    virtual void setSequenceNumber(int sequenceNumber);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const packetRecord& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, packetRecord& obj) {obj.parsimUnpack(b);}

#endif // ifndef __PACKETRECORD_M_H

