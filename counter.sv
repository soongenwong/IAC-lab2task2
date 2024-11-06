module counter #(
    parameter ADDRESS_WIDTH = 8
)(
    input logic clk,
    input logic rst,
    input logic en,
    input logic [ADDRESS_WIDTH-1:0] incr,
    output logic [ADDRESS_WIDTH-1:0] addr1,
    output logic [ADDRESS_WIDTH-1:0] addr2
);

    always_ff @(posedge clk) begin
        if (rst) begin
            addr1 <= 8'h00;
            addr2 <= 8'h00;
        end else if (en) begin
            addr1 <= addr1 + incr;
            addr2 <= addr2 + incr;
        end
    end

endmodule
