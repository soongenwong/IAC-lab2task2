module sinegen #(
    parameter   ADDRESS_WIDTH = 8,
                DATA_WIDTH = 8
)(
    input logic clk,
    input logic rst,
    input logic en,
    input logic [DATA_WIDTH-1:0] incr,
    input logic [ADDRESS_WIDTH-1:0] offset,
    output logic [DATA_WIDTH-1:0] dout1,  // Make sure these outputs are defined
    output logic [DATA_WIDTH-1:0] dout2
);

    logic [ADDRESS_WIDTH-1:0] addr1;
    logic [ADDRESS_WIDTH-1:0] addr2;

    counter #(
        .ADDRESS_WIDTH(ADDRESS_WIDTH)
    ) counter(
        .clk(clk),
        .rst(rst),
        .en(en),
        .incr(incr),
        .addr1(addr1),
        .addr2(addr2)
    );

    rom #(
        .ADDRESS_WIDTH(ADDRESS_WIDTH),
        .DATA_WIDTH(DATA_WIDTH)
    ) rom(
        .clk(clk),
        .addr1(addr1),
        .addr2(addr2),
        .offset(offset),
        .dout1(dout1),
        .dout2(dout2)
    );

endmodule
