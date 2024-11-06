module rom #(
    parameter ADDRESS_WIDTH = 8,
              DATA_WIDTH = 8
)(
    input logic clk,
    input logic [ADDRESS_WIDTH-1:0] addr1,
    input logic [ADDRESS_WIDTH-1:0] addr2,
    input logic [ADDRESS_WIDTH-1:0] offset,
    output logic [DATA_WIDTH-1:0] dout1,
    output logic [DATA_WIDTH-1:0] dout2
);

    logic [DATA_WIDTH-1:0] memory [0:255];

    initial begin
        $readmemh("sinerom.mem", memory);  // Make sure filename matches exactly
    end

    // Use combinational logic instead of sequential
    assign dout1 = memory[addr1];
    assign dout2 = memory[(addr2 + offset) & 8'hFF];  // Use AND for wrapping

endmodule
