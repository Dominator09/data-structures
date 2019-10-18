var converter = require('xml2json');

 
var xml = '<s:Envelope xmlns:s="http://schemas.xmlsoap.org/soap/envelope/"><s:Header><MessageHeader xmlns="http://www.ecentricswitch.co.za/paymentgateway/v1"> <MessageDateTime>2014-09-29T15:43:09.987</MessageDateTime> <MessageID>5B75D037-B1C4-4CA3-B388-39803BF93076</MessageID>   </MessageHeader> </s:Header></s:Envelope>';
console.log("input -> %s", xml)
 
// xml to json
var json = converter.toJson(xml);
console.log("to json -> %s", json);
 


